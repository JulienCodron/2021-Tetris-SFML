#pragma once
#include "GraphiqueManager.hpp"
#include "ClicManager.hpp"
#include "MemoryManager.hpp"
#include "DEFINITIONS.hpp"

class GameData {
public:
	sf::RenderWindow window;
	sf::Event ev;
	sf::Clock dtClock;

	//manager
	StateEnum ActualState;
	MemoryManager memory_m;
	GraphiqueManager assets_m;
	ClicManager clic_m;

	GameData() { ActualState = StateEnum::MainMenu; };
};
