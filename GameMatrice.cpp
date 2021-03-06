#include "GameMatrice.hpp"

GameMatrice::GameMatrice(){}

void GameMatrice::UpdateTetromino(Tetromino *t) {
	//update block of matrice with a tetromino, using his postion and his blocks
	for (int i = 0; i <= 3; ++i)
		for (int j = 0; j <= 3; ++j) 
			if (IsOnMatrice(t->posY + i, t->posX + j)) {
				if (t->piece[i][j].active) {
					matrice[t->posY + i][t->posX + j].active = true;
					matrice[t->posY + i][t->posX + j].color = t->piece[i][j].color;
				}
			}		
}

bool GameMatrice::IsOnMatrice(int i, int j) {
	//return true if the part of the tetromino matrix is on on the main matrix
	return (i < ySize && i >= 0) && (j < xSize && j >= 0);
}

bool GameMatrice::CanMooveDown(Tetromino *t) {
	//Check if the Tetromino can moove down or not
	DeleteTetromino(t);
	for (int i = 0; i <= 3; ++i)
		for (int j = 0; j <= 3; ++j) 
			if (t->piece[i][j].active) {
				if ((!IsOnMatrice(t->posY + i + 1, t->posX + j)) || matrice[t->posY + i + 1][t->posX + j].active) {
					UpdateTetromino(t);
					return false;
				}
			}		
	UpdateTetromino(t);
	return true;
}

bool GameMatrice::CanRotate(Tetromino* t) {
	//Check if the Tetromino can rotate or not
	for (int i = 0; i <= 3; ++i)
		for (int j = 0; j <= 3; ++j) {
			if (!IsOnMatrice(t->posY + i, t->posX + j))
				return false;
			if (matrice[t->posY + i][t->posX + j].active && !t->piece[i][j].active)
				return false;
		}
	return true;
}

void GameMatrice::MoveDown(Tetromino* t) {
	//Moove down the position of the Tetromino on the matrice
	if (CanMooveDown(t)) {
		DeleteTetromino(t);
		t->posY += 1;
	}
}

void GameMatrice::DeleteTetromino(Tetromino* t) {	
	//Remove a Tetromino from the matrice
	for (int i = 0; i <= 3; ++i)
		for (int j = 0; j <= 3; ++j)
			if (IsOnMatrice(t->posY + i, t->posX + j)) {
				if (t->piece[i][j].active) {
					matrice[t->posY + i][t->posX + j].active = false;
				}
			}
}

void GameMatrice::MoveLeft(Tetromino *t) {
	//Check if the Tetromino can move left and do it
	DeleteTetromino(t);
	for (int i = 0; i <= 3; ++i)
		for (int j = 0; j <= 3; ++j)
			if (t->piece[i][j].active) {
				if ((!IsOnMatrice(t->posY + i, t->posX + j - 1)) || matrice[t->posY + i][t->posX + j - 1].active) {
					return;
				}
			}
	t->posX -= 1;
}

void GameMatrice::MoveRight(Tetromino *t) {
	//Check if the Tetromino can move to rigth and do it
	DeleteTetromino(t);
	for (int i = 0; i <= 3; ++i)		
		for (int j = 0; j <= 3; ++j)
			if (t->piece[i][j].active) {
				if ((!IsOnMatrice(t->posY + i, t->posX + j + 1)) || matrice[t->posY + i][t->posX + j + 1].active) {
					UpdateTetromino(t);
					return;
				}
			}
	t->posX += 1;
}

void GameMatrice::Rotate(Tetromino* t) {
	//Rotate the Tetromino if he can
	Tetromino tmp = Tetromino();
	tmp.posX = t->posX;
	tmp.posY = t->posY;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			tmp.piece[i][j] = t->piece[4 - j - 1][i];
		}
	}

	DeleteTetromino(t);
	if (CanRotate(&tmp)) {
		for (int i = 0; i <= 3 ; ++i) {
			for (int j = 0; j <= 3 ; ++j) {
				t->piece[i][j].active = tmp.piece[i][j].active;
				t->piece[i][j].color = tmp.piece[i][j].color;
			}
		}	
	}
}

int GameMatrice::DeleteLine() {
	// Delete complete lines and return number of lines deleted
	bool line = false;
	int nbLineDel = 0;
	for (int a = 0; a < ySize; ++a) 
		if (LineComplete(matrice[a])) {
			nbLineDel++;
			for (int y = a; y > 0; --y)
				for (int j = 0; j < xSize; ++j)
					matrice[y][j] = matrice[y - 1][j];
		}	
	return nbLineDel;
}

bool GameMatrice::LineComplete(Block * line){
	//check if a line is full of block
	for (int a = 0; a < xSize; ++a) 
		if (!line[a].active) 
			return false;
	return true;
}

bool GameMatrice::CanSwap(Tetromino * t1, Tetromino* t2) {
	//check if you can swap with the tetromino holded
	for (int i = 0; i <= 3; ++i) {
		for (int j = 0; j <= 3; ++j) {
			if(t2->piece[i][j].active && matrice[i+ t1->posY][j+ t1->posX].active && !t1->piece[i][j].active)
				return false;
		}
	}
	return true;
}


bool GameMatrice::GameOver() {
	//check if the game is over
	bool line = false;
	int j = 0;
	for (int i = 0; i < ySize; ++i){
		line = false;
		j = 0;
		while (!line && j < xSize){
			++j;
			if (matrice[i][j].active)
				line = true;
		}
		if (!line) 
			return false;	
	}
	return true;
}
