#pragma once
#include "GameData.hpp"
#include "Tetromino.hpp"
#include "GameMatrice.hpp"
#include "State.hpp"


class GameState : public State {
private:
	GameData* data;

	//all the game settings
	Tetromino holded_Tetromino;
	Tetromino current_Tetromino;
	Tetromino seconde_Tetromino;
	Tetromino third_Tetromino;
	Tetromino fourth_Tetromino;
	GameMatrice game_matrice;
	bool initialised = false;
	bool lastChance = false;
	sf::Clock start;
	int goal[30] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12 };
	float speed = 750 ;
	int lvl = 0;
	int lineComplet = 0;
	int score = 0;

	//sprite ans things to draw
	sf::Text nb_line_left;
	sf::Text current_lvl;
	sf::Text current_score;
	sf::Text best_score;
	sf::RectangleShape advanced_bar;
	sf::Sprite cube;
	sf::Sprite litleCube;
	sf::Sprite background;

public:
	GameState() {};
	GameState(GameData* gameData);
	void Init();
	void HandleInput();
	void Update();
	void Draw(float dt);
	void DrawSideTetromino();
	void HoldTetromino();
	void DrawSideInfo();
};