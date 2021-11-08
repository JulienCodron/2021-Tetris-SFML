#pragma once
#include "GameData.hpp"
#include "State.hpp"

class GameOverState : public State {
private:
	GameData* data;
	bool initialised = false;
	sf::Sprite gameOver;
	sf::Sprite restart;
	sf::Sprite quit;
	sf::RectangleShape filter;
	

public:
	GameOverState() {};
	GameOverState(GameData* gameData);
	void Init();
	void HandleInput();
	void Update();
	void Draw(float dt);
};