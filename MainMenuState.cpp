#include "MainMenuState.hpp"

MainMenuState::MainMenuState(GameData *gameData){
    data = gameData;
};

void MainMenuState::Init(){
    //load all assets and init their position/color
    data->assets_m.LoadTexture("Background", MAIN_MENU_BACKGROUND_FP);
    data->assets_m.LoadTexture("Title", MAIN_MENU_TITLE_FP );
    data->assets_m.LoadTexture("MainMenuInfo", MAIN_MENU_INFO_FP );

	background.setTexture(data->assets_m.GetTexture("Background"));
	title.setTexture(data->assets_m.GetTexture("Title"));
    info.setTexture(data->assets_m.GetTexture("MainMenuInfo"));

	title.setPosition((SCREEN_WIDTH / 2) - (title.getGlobalBounds().width / 2),
		(SCREEN_HEIGHT / 5)); 
    info.setPosition((SCREEN_WIDTH / 2) - (info.getGlobalBounds().width / 2),
		(SCREEN_HEIGHT / 3)); 
}

void MainMenuState::HandleInput() {
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

void MainMenuState::Update() {
    if (!initialised) {
        Init();
        initialised = true;
    }
}

void MainMenuState::Draw(float dt) {
    data->window.clear(sf::Color::Black);

    data->window.draw(background);
    data->window.draw(title);
    data->window.draw(info);

    data->window.display();
}

