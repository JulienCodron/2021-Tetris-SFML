#pragma once
#include "State.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "GameOverState.hpp"
#include "GameState.hpp"


class StateManager {
public:
	StateEnum ActualState;
	MainMenuState mainMenuState;
	GameState gameState;
	GameOverState gameOverState;
	sf::Clock dt;

	StateManager():ActualState(StateEnum::MainMenu){};
	StateManager(GameData* gameData);
	void Init();
	void HandleInput();
	void Update();
	void Draw(float dt);
};