#include "GameOverState.hpp"

GameOverState::GameOverState(GameData* gameData):data(gameData) {
};

void GameOverState::Init() {
    data->assets_m.LoadTexture("GameOver", GAMEOVER);
    data->assets_m.LoadTexture("Restart", RESTART);
    data->assets_m.LoadTexture("Quit", QUIT);

    gameOver.setTexture(data->assets_m.GetTexture("GameOver"));
    restart.setTexture(data->assets_m.GetTexture("Restart"));
    quit.setTexture(data->assets_m.GetTexture("Quit"));

    gameOver.setPosition((SCREEN_WIDTH / 2) - (gameOver.getGlobalBounds().width / 2),
        (SCREEN_HEIGHT / 10));
    restart.setPosition((SCREEN_WIDTH / 2) - (restart.getGlobalBounds().width / 2),
        (SCREEN_HEIGHT / 4));
    quit.setPosition((SCREEN_WIDTH / 2) - (quit.getGlobalBounds().width / 2),
        (SCREEN_HEIGHT / 2));

    filter.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    filter.setFillColor(sf::Color(0, 0, 0, 2));
}

void GameOverState::HandleInput() {
    switch (data->ev.type) {
    case sf::Event::Closed:
        data->window.close();
        break;

    case sf::Event::KeyPressed:
        switch (data->ev.key.code) {
            case sf::Keyboard::Escape:
                data->window.close();
                break;

            case sf::Keyboard::Enter:
                data->ActualState = StateEnum::Game;
                break;
        }
   

    default:
        break;
    }
}

void GameOverState::Update() {
    if (!initialised) {
        Init();
        initialised = true;
    }
}

void GameOverState::Draw(float dt) {
    data->window.draw(gameOver);
    data->window.draw(restart);
    data->window.draw(quit);
    data->window.draw(filter);

    data->window.display();
}

