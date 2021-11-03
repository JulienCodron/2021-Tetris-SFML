#include "GameOverState.hpp"

GameOverState::GameOverState(GameData* gameData):data(gameData) {
};

void GameOverState::Init() {
    data->assets_m.LoadTexture("GameOver", GAMEOVER);

    gameOver.setTexture(data->assets_m.GetTexture("GameOver"));

    gameOver.setPosition((SCREEN_WIDTH / 2) - (gameOver.getGlobalBounds().width / 2),
        (SCREEN_HEIGHT / 2) - (gameOver.getGlobalBounds().height / 2 * 0.1));
}

void GameOverState::HandleInput() {
    switch (data->ev.type) {
    case sf::Event::Closed:
        data->window.close();
        break;

    case sf::Event::KeyPressed:
        if (data->ev.key.code == sf::Keyboard::Escape)
            data->window.close();
        break;

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

    data->window.display();
}

