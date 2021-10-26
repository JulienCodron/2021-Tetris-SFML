#pragma once
#include "GraphiqueManager.hpp"
#include "State.hpp"
#include "ClicManager.hpp"
#include "MemoryManager.hpp"
#include "DEFINITIONS.hpp"

class GameData {
public:
	sf::RenderWindow window;
	sf::Event ev;
	sf::Clock dtClock;

	//MemoryManager memory_m;
	GraphiqueManager assets;
	ClicManager clic;
	State* ActualState;

	GameData();
	~GameData();

};
