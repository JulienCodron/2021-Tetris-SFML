#include "MainMenuState.hpp"

MainMenuState::MainMenuState(GameData *gameData){
    data = gameData;
};

void MainMenuState::Init(){
    data->assets_m.LoadTexture("Background", MAIN_MENU_BACKGROUND_FP);
    data->assets_m.LoadTexture("Title", MAIN_MENU_TITLE_FP );

	background.setTexture(data->assets_m.GetTexture("Background"));
	title.setTexture(data->assets_m.GetTexture("Title"));

	title.setPosition((SCREEN_WIDTH / 2) - (title.getGlobalBounds().width / 2),
		(SCREEN_HEIGHT / 2) - (title.getGlobalBounds().height / 2 * 0.1)); 
}

void MainMenuState::HandleInput() {
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

void MainMenuState::Update() {

}

void MainMenuState::Draw(float dt) {
    data->window.clear(sf::Color::Black);

    data->window.draw(background);
    data->window.draw(title);

    data->window.display();
}

