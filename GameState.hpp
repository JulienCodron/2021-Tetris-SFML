#pragma once
#include "GameData.hpp"
#include <sstream>
#include "Tetromino.hpp"
#include "GameMatrice.hpp"

class GameState : public State {
private:
	GameData* data;
	Tetromino* current_Tetromino;
	GameMatrice game_matrice;
	bool initialised = false;

	sf::Sprite cube;
	sf::Sprite background;

public:
	GameState() {};
	~GameState();
	GameState(GameData* gameData);
	void Init();
	void HandleInput();
	void Update();
	void Draw(float dt);
};