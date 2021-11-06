#include "PauseState.hpp"

PauseState::PauseState(GameData * gameData) :data(gameData) {
};

void PauseState::Init() {
    data->assets_m.LoadTexture("Pause", PAUSE);
    data->assets_m.LoadTexture("Continue", CONTINUE);
    data->assets_m.LoadTexture("Quit", QUIT);

    pause.setTexture(data->assets_m.GetTexture("Pause"));
    continuer.setTexture(data->assets_m.GetTexture("Continue"));
    quit.setTexture(data->assets_m.GetTexture("Quit"));

    pause.setPosition((SCREEN_WIDTH / 2) - (pause.getGlobalBounds().width / 2),
        (SCREEN_HEIGHT / 10));
    continuer.setPosition((SCREEN_WIDTH / 2) - (continuer.getGlobalBounds().width / 2),
        (SCREEN_HEIGHT / 4));
    quit.setPosition((SCREEN_WIDTH / 2) - (quit.getGlobalBounds().width / 2),
        (SCREEN_HEIGHT / 2));

    filter.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    filter.setFillColor(sf::Color(0,0,0,2));
}

void PauseState::HandleInput() {
    switch (data->ev.type) {
    case sf::Event::Closed:
        data->window.close();
        break;

    case sf::Event::KeyPressed:
        switch (data->ev.key.code) {
        case sf::Keyboard::Escape:
            data->window.close();
            break;

        case sf::Keyboard::Space:
        case sf::Keyboard::Enter:
            data->ActualState = StateEnum::Game;
            break;
        }


    default:
        break;
    }
}

void PauseState::Update() {
    if (!initialised) {
        Init();
        initialised = true;
    }
}

void PauseState::Draw(float dt) {
    data->window.draw(pause);
    data->window.draw(continuer);
    data->window.draw(quit);
    data->window.draw(filter);

    data->window.display();
}

