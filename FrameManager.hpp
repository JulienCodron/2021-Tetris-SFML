#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "State.hpp"


class FrameManager {
	protected:
		sf::RenderWindow window;
		sf::Event ev;
		sf::Clock dtClock;
		State *ActualState;
		float dt;

	public:
		FrameManager(int width, int length, std::string Title);
		void Run();
		void UpdateDt();
};