#include "GameState.hpp"

GameState::GameState(GameData* gameData) : data(gameData) {
    current_Tetromino = Tetromino(TetrominoEnum(rand() % 7));
    seconde_Tetromino = Tetromino(TetrominoEnum(rand() % 7));
    third_Tetromino = Tetromino(TetrominoEnum(rand() % 7));
    fourth_Tetromino = Tetromino(TetrominoEnum(rand() % 7));
}

void GameState::Init() {
    //load all assets and init their position/color
    data->assets_m.LoadTexture("Cube", CUBE);
    data->assets_m.LoadTexture("LitleCube", LITLE_CUBE);
    data->assets_m.LoadTexture("Background", GAME_BACKGROUND_FP);
    data->assets_m.LoadFont("Font", FONT);

    cube.setTexture(data->assets_m.GetTexture("Cube"));
    litleCube.setTexture(data->assets_m.GetTexture("LitleCube"));
    background.setTexture(data->assets_m.GetTexture("Background"));
    advanced_bar.setSize(sf::Vector2f(86, 23));
    advanced_bar.setFillColor(sf::Color(25, 91, 115));
    advanced_bar.setPosition(ADVANCED_BAR_WIDTH_POSTION, ADVANCED_BAR_HEIGHT_POSTION);

    nb_line_left.setFont(data->assets_m.GetFont("Font"));
    nb_line_left.setCharacterSize(30);
    nb_line_left.setFillColor(sf::Color(244, 226, 172));
    nb_line_left.setPosition(LINELEFT_INF_WIDTH_POSTION, LINELEFT_HEIGHT_POSTION);

    current_lvl.setFont(data->assets_m.GetFont("Font"));
    current_lvl.setCharacterSize(60);
    current_lvl.setFillColor(sf::Color(244, 226, 172));
    current_lvl.setPosition(LVL_INF_WIDTH_POSTION, LVL_HEIGHT_POSTION);

    current_score.setFont(data->assets_m.GetFont("Font"));
    current_score.setCharacterSize(25);
    current_score.setFillColor(sf::Color(244, 226, 172));
    current_score.setPosition(SCORE_WIDTH_POSTION, SCORE_HEIGHT_POSTION);

    best_score.setFont(data->assets_m.GetFont("Font"));
    best_score.setCharacterSize(25);
    best_score.setFillColor(sf::Color(244, 226, 172));
    best_score.setPosition(BEST_SCORE_WIDTH_POSTION, BEST_SCORE_HEIGHT_POSTION);

    //init a timer use to moove the tetromino
    start.restart();
}

void GameState::HandleInput() {
    switch (data->ev.type) {
    case sf::Event::Closed:
        data->window.close();
        break;

    case sf::Event::KeyPressed:
        switch (data->ev.key.code) {
            case sf::Keyboard::Left:
            case sf::Keyboard::Q:
                game_matrice.MoveLeft(&current_Tetromino);
                break;

            case sf::Keyboard::Right:
            case sf::Keyboard::D:
                game_matrice.MoveRight(&current_Tetromino);
                break;

            case sf::Keyboard::Up:
            case sf::Keyboard::Z:
                game_matrice.Rotate(&current_Tetromino);
                break;

            case sf::Keyboard::Down:
            case sf::Keyboard::S:
                game_matrice.MoveDown(&current_Tetromino);
                break;

            case sf::Keyboard::Enter:
            case sf::Keyboard::Space:
            case sf::Keyboard::Num0:
                HoldTetromino();
                break;

            case sf::Keyboard::Escape:
                //Change the state to pause the game
                data->ActualState = StateEnum::PauseMenu;
                break;

        }  
        break;

    default:
        break;
    }
}

void GameState::Update() {
    if (!initialised) {
        Init();
        initialised = true;
    }

    //Check if the tetromino can moove down 
    if (game_matrice.CanMooveDown(&current_Tetromino)) {
        //move the tetromino if "speed" (in ms) pass and redraw him on the matrix
        game_matrice.DeleteTetromino(&current_Tetromino);
        if (start.getElapsedTime().asMilliseconds() >= speed)
        {
            current_Tetromino.posY += 1;          
            start.restart();
        }
        game_matrice.UpdateTetromino(&current_Tetromino);
        lastChance = true;
    }
    else {
        if (lastChance) {
            //allow the player to move the tetromino at the end
            if (start.getElapsedTime().asMilliseconds() >= speed)
            {
                lastChance = false;
                start.restart();
            }
        }
        else {
            //check if game is over
            if (game_matrice.GameOver()) {
                Draw(0);
                data->ActualState = StateEnum::GameOverMenu;     //change state if game is over 

                return;
            }
            int linedeleted = game_matrice.DeleteLine();
            //count lines complete and delete them
            if (linedeleted > 0) {
                lineComplet += linedeleted;
                score += 10 * linedeleted + 10 * (linedeleted - 1);
            }

            if (lineComplet >= goal[lvl]) {
                lineComplet = lineComplet - goal[lvl];
                lvl += 1;
                //increment speed of the game
                if (lvl > 7)
                    speed -= 20;
                else
                    speed -= 50;
                score += 100;
            }
            //moove to next tetromino
            current_Tetromino = seconde_Tetromino;
            seconde_Tetromino = third_Tetromino;
            third_Tetromino = fourth_Tetromino;
            fourth_Tetromino = Tetromino(TetrominoEnum(rand() % 7));
        }    
    }
}

void GameState::HoldTetromino() {
    // this function allow to the player to hold a tetromino
    if (holded_Tetromino.estVide()){
        game_matrice.DeleteTetromino(&current_Tetromino);
        holded_Tetromino = current_Tetromino;
        current_Tetromino = seconde_Tetromino;
        seconde_Tetromino = third_Tetromino;
        third_Tetromino = fourth_Tetromino;
        fourth_Tetromino = Tetromino(TetrominoEnum(rand() % 7));
    }
    else {
        holded_Tetromino.posX = current_Tetromino.posX;
        holded_Tetromino.posY = current_Tetromino.posY;
        if (game_matrice.CanSwap(&current_Tetromino,&holded_Tetromino)) {
            game_matrice.DeleteTetromino(&current_Tetromino);
            std::swap(holded_Tetromino, current_Tetromino);
        }    
    }
}

void GameState::Draw(float dt) {
    data->window.clear(sf::Color::Black);
    data->window.draw(background);

    // draw all the bloc active on the matrix
    for (int i = 0; i < game_matrice.ySize; ++i) {
        for (int j = 0; j < game_matrice.xSize; ++j) {
            if (game_matrice.matrice[i][j].active) {
                cube.setColor(game_matrice.matrice[i][j].color);
                cube.setPosition(PLAYGROUND_WIDTH_POSTION + BLOCK_SIZE  * j , PLAYGROUND_HEIGHT_POSTION + BLOCK_SIZE * i);
                data->window.draw(cube);
            }
        }
    }

    DrawSideTetromino();
    DrawSideInfo();

    data->window.display();
}

void GameState::DrawSideTetromino() {  
    for (int i = 0; i <= 3; ++i) {
        for (int j = 0; j <= 3; ++j) {
            if (holded_Tetromino.piece[i][j].active) {
                litleCube.setColor(holded_Tetromino.piece[i][j].color);
                if (holded_Tetromino.type == TetrominoEnum::R || holded_Tetromino.type == TetrominoEnum::I)
                    litleCube.setPosition(SIDE_TETROMINO_WIDTH_POSTION - 16 + LITLE_BLOCK_SIZE * j, HOLDED_TETROMINO_HEIGHT_POSTION + LITLE_BLOCK_SIZE * i);
                else
                    litleCube.setPosition(SIDE_TETROMINO_WIDTH_POSTION -15 + LITLE_BLOCK_SIZE * j, HOLDED_TETROMINO_HEIGHT_POSTION + LITLE_BLOCK_SIZE * i);
                data->window.draw(litleCube);
            }

            if (seconde_Tetromino.piece[i][j].active) {
                litleCube.setColor(seconde_Tetromino.piece[i][j].color);
                if(seconde_Tetromino.type == TetrominoEnum::R || seconde_Tetromino.type == TetrominoEnum::I)
                    litleCube.setPosition(SIDE_TETROMINO_WIDTH_POSTION - 16 + LITLE_BLOCK_SIZE * j, SECONDE_TETROMINO_HEIGHT_POSTION + LITLE_BLOCK_SIZE * i);
                else
                    litleCube.setPosition(SIDE_TETROMINO_WIDTH_POSTION + LITLE_BLOCK_SIZE * j, SECONDE_TETROMINO_HEIGHT_POSTION + LITLE_BLOCK_SIZE * i);
                data->window.draw(litleCube);
            }

            if (third_Tetromino.piece[i][j].active) {
                litleCube.setColor(third_Tetromino.piece[i][j].color);
                if (third_Tetromino.type == TetrominoEnum::R || third_Tetromino.type == TetrominoEnum::I)
                    litleCube.setPosition(SIDE_TETROMINO_WIDTH_POSTION - 16 + LITLE_BLOCK_SIZE * j, THIRD_TETROMINO_HEIGHT_POSTION + LITLE_BLOCK_SIZE * i);
                else
                    litleCube.setPosition(SIDE_TETROMINO_WIDTH_POSTION + LITLE_BLOCK_SIZE * j, THIRD_TETROMINO_HEIGHT_POSTION + LITLE_BLOCK_SIZE * i);
                data->window.draw(litleCube);
            }

            if (fourth_Tetromino.piece[i][j].active) {
                litleCube.setColor(fourth_Tetromino.piece[i][j].color);
                if (fourth_Tetromino.type == TetrominoEnum::R || fourth_Tetromino.type == TetrominoEnum::I)
                    litleCube.setPosition(SIDE_TETROMINO_WIDTH_POSTION - 16 + LITLE_BLOCK_SIZE * j, FOURTH_TETROMINO_HEIGHT_POSTION + LITLE_BLOCK_SIZE * i);
                else
                    litleCube.setPosition(SIDE_TETROMINO_WIDTH_POSTION + LITLE_BLOCK_SIZE * j, FOURTH_TETROMINO_HEIGHT_POSTION + LITLE_BLOCK_SIZE * i);
                data->window.draw(litleCube);
            }
        }
    }
}

void GameState::DrawSideInfo() {
    nb_line_left.setString(std::to_string(goal[lvl]-lineComplet));
    current_lvl.setString(std::to_string(lvl+1));
    current_score.setString(std::to_string(score));
    best_score.setString("1250");
    if (lvl >= 10) 
        current_lvl.setPosition(LVL_SUP_WIDTH_POSTION, LVL_HEIGHT_POSTION);
    
    if(goal[lvl] - lineComplet > 10)
        nb_line_left.setPosition(LINELEFT_SUP_WIDTH_POSTION, LINELEFT_HEIGHT_POSTION);
    else
        nb_line_left.setPosition(LINELEFT_INF_WIDTH_POSTION, LINELEFT_HEIGHT_POSTION);

    advanced_bar.setSize(sf::Vector2f(86/(goal[lvl])* lineComplet, 23));

    data->window.draw(nb_line_left);
    data->window.draw(current_lvl);
    data->window.draw(current_score);
    data->window.draw(best_score);
    data->window.draw(advanced_bar);
}
