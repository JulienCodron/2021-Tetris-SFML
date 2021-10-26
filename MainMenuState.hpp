#pragma once
#include "GameData.hpp"
#include <sstream>

class MainMenuState : public State {
private:
	sf::Sprite background;
	sf::Sprite title;

public:
	GameData* data;
	MainMenuState(GameData *gameData);
	void Init();
	void HandleInput();
	void Update();
	void Draw(float dt);
};