#include "GameState.hpp"

GameState::GameState(GameData* gameData) : data(gameData) {
   current_Tetromino = new Tetromino(TetrominoEnum(rand() % 7));
}

GameState::~GameState(){
    //delete current_Tetromino;
}


void GameState::Init() {
    data->assets_m.LoadTexture("Cube", CUBE);
    data->assets_m.LoadTexture("Background", MAIN_MENU_BACKGROUND_FP);

    cube.setTexture(data->assets_m.GetTexture("Cube"));
    background.setTexture(data->assets_m.GetTexture("Background"));
}

void GameState::HandleInput() {
    switch (data->ev.type) {
    case sf::Event::Closed:
        data->window.close();
        break;

    case sf::Event::KeyPressed:
        switch (data->ev.key.code) {
            case sf::Keyboard::Escape:
                data->window.close();
                break;

            case sf::Keyboard::Left:
            case sf::Keyboard::Q:
                game_matrice.MooveLeft(current_Tetromino);
                break;

            case sf::Keyboard::Right:
            case sf::Keyboard::D:
                game_matrice.MooveRight(current_Tetromino);
                break;
            
            case sf::Keyboard::Up:
            case sf::Keyboard::Z:
                game_matrice.Rotate(current_Tetromino);
                break;

            case sf::Keyboard::Down:
            case sf::Keyboard::S:
                game_matrice.MooveDown(current_Tetromino);
                break;

        }
        break;

    default:
        break;
    }
}

void GameState::Update() { 
   game_matrice.UpdateTetromino(current_Tetromino);
   if (game_matrice.CanMooveDown(current_Tetromino))
       //game_matrice.UpdatePosTetromino(current_Tetromino);
       ;
   else {
       game_matrice.DeleteLine();
       current_Tetromino = new Tetromino(TetrominoEnum(rand() % 7));
   }
}

void GameState::Draw(float dt) {
    data->window.clear(sf::Color::Black);
    data->window.draw(background);
    
  
    for (int i = 0; i < game_matrice.ySize; ++i) {
        for (int j = 0; j < game_matrice.xSize; ++j) {
            if (game_matrice.matrice[i][j].active) {
                cube.setTexture(data->assets_m.GetTexture("Cube"));
                cube.setColor(game_matrice.matrice[i][j].color);
                cube.setPosition(PLAYGROUND_WIDTH_POSTION + BLOCK_SIZE * j, PLAYGROUND_HEIGHT_POSTION + BLOCK_SIZE * i);
                data->window.draw(cube);
            }
        }
    }
    
    if (game_matrice.GameOver()) {
        data->ActualState = StateEnum::GameOverMenu;
    }
    
    
        
    data->window.display();
}

