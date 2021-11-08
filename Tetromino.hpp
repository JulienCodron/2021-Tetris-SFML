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
	//position of the tetromino on the matrix
	int posX;
	int posY;
	Block piece[4][4];
	TetrominoEnum type;
	Tetromino();
	Tetromino(TetrominoEnum type);
	bool estVide();
};