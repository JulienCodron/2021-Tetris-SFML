#pragma once
#include "GameData.hpp"


class GameOverState : public State {
private:
	GameData* data;
	sf::Sprite gameOver;


public:
	GameOverState() {};
	GameOverState(GameData* gameData);
	void Init();
	void HandleInput();
	void Update();
	void Draw(float dt);
};