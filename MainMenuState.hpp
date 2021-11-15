#pragma once
#include "GameData.hpp"
#include "State.hpp"


class MainMenuState : public State {
private:
	GameData* data;
	bool initialised = false;

	//sprite 
	sf::Sprite background;
	sf::Sprite title;
	sf::Sprite info;
	sf::Sprite control;

public:
	MainMenuState() {};
	MainMenuState(GameData *gameData);
	void Init();
	void HandleInput();
	void Update();
	void Draw(float dt);
};