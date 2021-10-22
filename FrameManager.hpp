#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "State.hpp"
#include "GraphiqueManager.hpp"
#include "ClicManager.hpp"

class GameData {
public:
	sf::RenderWindow window;
	sf::Event ev;
	sf::Clock dtClock;

	GraphiqueManager assets;
	ClicManager clic;
	State * ActualState;

	GameData();
	GameData(const GameData& gd);
	void Init();
};


class FrameManager {
	protected:
		GameData * data;	
		float dt;

	public:
		FrameManager(int width, int length, std::string Title);
		void Run();
		void UpdateDt();
};