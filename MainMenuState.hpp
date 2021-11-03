#pragma once
#include "GameData.hpp"
#include <sstream>

class MainMenuState : public State {
private:
	GameData* data;
	sf::Sprite background;
	sf::Sprite title;

public:
	MainMenuState() {};
	MainMenuState(GameData *gameData);
	void Init();
	void HandleInput();
	void Update();
	void Draw(float dt);
};