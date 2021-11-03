#pragma once
#include "Tetromino.hpp"


class GameMatrice {

public:
	const static int xSize = 10;
	const static int ySize = 20;
	Block matrice[ySize][xSize];
	GameMatrice();
	void print();
	bool CanMooveDown(Tetromino* t);
	bool CanRotate(Tetromino * t);
	void DeleteLine();
	void UpdateTetromino(Tetromino* t);
	void DeleteTetromino(Tetromino* t);
	bool IsOnMatrice(int i, int j);
	void MooveLeft(Tetromino* t);
	void MooveRight(Tetromino* t);
	void MooveDown(Tetromino* t);
	void Rotate(Tetromino* t);
	bool LineComplete(Block * line);
	bool GameOver();
};