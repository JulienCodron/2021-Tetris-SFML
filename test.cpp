#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "State.hpp"
#include "GraphiqueManager.hpp"
#include "ClicManager.hpp"
#include "FrameManager.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"

class GameDatatest {
public:
    GraphiqueManager* assets;
	ClicManager* clic;
	//State* ActualState;
 
    sf::Sprite background;
    sf::Sprite title;
    sf::RenderWindow window;
    sf::Event ev;
    sf::Clock dtClock;

    GameDatatest() {
        assets = new GraphiqueManager();
        clic = new ClicManager();
        (*assets).LoadTexture("Background", MAIN_MENU_BACKGROUND_FP);
        (*assets).LoadTexture("Title", MAIN_MENU_TITLE_FP);

        background.setTexture((*assets).GetTexture("Background"));
        title.setTexture((*assets).GetTexture("Title"));

        title.setPosition((SCREEN_WIDTH / 2) - (title.getGlobalBounds().width / 2),
            (SCREEN_HEIGHT / 2) - (title.getGlobalBounds().height / 2 * 0.1));
    };

    ~GameDatatest() {
        delete assets;
        delete clic;
        //delete ActualState;
    };
};