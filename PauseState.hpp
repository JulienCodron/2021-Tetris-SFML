#pragma once
#include "GameData.hpp"


class PauseState : public State {
private:
	GameData* data;
	bool initialised = false;
	sf::Sprite pause;
	sf::Sprite continuer;
	sf::Sprite quit;
	sf::RectangleShape filter;


public:
	PauseState() {};
	PauseState(GameData* gameData);
	void Init();
	void HandleInput();
	void Update();
	void Draw(float dt);
};