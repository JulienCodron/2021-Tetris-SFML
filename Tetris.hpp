#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>

class Tetris {
	protected:
		sf::RenderWindow window;
		sf::Event ev;
		sf::Clock clock;

	public:
		Tetris(int width, int length, std::string Title);
		~Tetris();
		void Run();
};