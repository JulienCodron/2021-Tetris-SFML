#pragma once
#include "DEFINITIONS.hpp"
#include "GraphiqueManager.hpp"

class Block {

public:
	bool active = false;
	sf::Color color;

	Block() {};
	void print();
};

class Tetromino {
public:
	int posX;
	int posY;
	Block piece[4][4];
	Tetromino();
	Tetromino(TetrominoEnum type);
};