#include "Tetromino.hpp"

Tetromino::Tetromino() : posX(3), posY(-3) {}

Tetromino::Tetromino(TetrominoEnum type) : posX(3), type(type) {
	posY = -2;
	switch (type) {
	case TetrominoEnum::S1:
		piece[2][0].active = true;
		piece[2][0].color = sf::Color(COLOR_RED);
		piece[2][1].active = true;
		piece[2][1].color = sf::Color(COLOR_RED);
		piece[1][1].active = true;
		piece[1][1].color = sf::Color(COLOR_RED);
		piece[1][2].active = true;
		piece[1][2].color = sf::Color(COLOR_RED);
		break;
	case TetrominoEnum::S2:
		piece[1][0].active = true;
		piece[1][0].color = sf::Color(COLOR_YELLOW);
		piece[1][1].active = true;
		piece[1][1].color = sf::Color(COLOR_YELLOW);
		piece[2][1].active = true;
		piece[2][1].color = sf::Color(COLOR_YELLOW);
		piece[2][2].active = true;
		piece[2][2].color = sf::Color(COLOR_YELLOW);
		break;
	case TetrominoEnum::L1:
		piece[2][0].active = true;
		piece[2][0].color = sf::Color(COLOR_GREEN);
		piece[2][1].active = true;
		piece[2][1].color = sf::Color(COLOR_GREEN);
		piece[2][2].active = true;
		piece[2][2].color = sf::Color(COLOR_GREEN);
		piece[1][0].active = true;
		piece[1][0].color = sf::Color(COLOR_GREEN);
		break;
	case TetrominoEnum::L2:
		piece[2][0].active = true;
		piece[2][0].color = sf::Color(COLOR_ORANGE);
		piece[2][1].active = true;
		piece[2][1].color = sf::Color(COLOR_ORANGE);
		piece[2][2].active = true;
		piece[2][2].color = sf::Color(COLOR_ORANGE);
		piece[1][2].active = true;
		piece[1][2].color = sf::Color(COLOR_ORANGE);
		break;
	case TetrominoEnum::I:
		piece[2][0].active = true;
		piece[2][0].color = sf::Color(COLOR_PURPLE);
		piece[2][1].active = true;
		piece[2][1].color = sf::Color(COLOR_PURPLE);
		piece[2][2].active = true;
		piece[2][2].color = sf::Color(COLOR_PURPLE);
		piece[2][3].active = true;
		piece[2][3].color = sf::Color(COLOR_PURPLE);
		break;
	case TetrominoEnum::T:
		piece[1][1].active = true;
		piece[1][1].color = sf::Color(COLOR_DARK_GREEN);
		piece[2][0].active = true;
		piece[2][0].color = sf::Color(COLOR_DARK_GREEN);
		piece[2][1].active = true;
		piece[2][1].color = sf::Color(COLOR_DARK_GREEN);
		piece[2][2].active = true;
		piece[2][2].color = sf::Color(COLOR_DARK_GREEN);
		break;
	case TetrominoEnum::R:
		piece[1][1].active = true;
		piece[1][1].color = sf::Color(COLOR_BLUE);
		piece[1][2].active = true;
		piece[1][2].color = sf::Color(COLOR_BLUE);
		piece[2][1].active = true;
		piece[2][1].color = sf::Color(COLOR_BLUE);
		piece[2][2].active = true;
		piece[2][2].color = sf::Color(COLOR_BLUE);
		break;
	}	
}

bool Tetromino::estVide() {
	for (int i = 0; i <= 3; ++i) {
		for (int j = 0; j <= 3; ++j) {
			if (piece[i][j].active) {
				return false;
			}
		}
	}
	return true;
}