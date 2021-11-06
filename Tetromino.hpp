#pragma once
#include "DEFINITIONS.hpp"
#include "GraphiqueManager.hpp"

class Block {

public:
	bool active = false;
	sf::Color color;

	Block() {};
};

class Tetromino {
public:
	int posX;
	int posY;
	Block piece[4][4];
	TetrominoEnum type;
	Tetromino();
	Tetromino(TetrominoEnum type);
	bool estVide();
};