#pragma once
#include "State.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "GameOverState.hpp"
#include "GameState.hpp"
#include "PauseState.hpp"


class StateManager {
public:
	GameData *data;
	StateEnum ActualState;
	StateEnum LastState;
	MainMenuState mainMenuState;
	GameState gameState;
	PauseState pauseState;
	GameOverState gameOverState;
	sf::Clock dt;

	StateManager():ActualState(StateEnum::MainMenu){};
	StateManager(GameData* gameData);
	void Init();
	void HandleInput();
	void Update();
	void Draw(float dt);
	void ComeFromGameOver();
};