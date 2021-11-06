#include "StateManager.hpp"


StateManager::StateManager(GameData* gameData) : data(gameData){
	//create all states and initialise the state manager on the MainMenuState.
	mainMenuState = MainMenuState(gameData);
	gameOverState = GameOverState(gameData);
	pauseState = PauseState(gameData);
	LastState = StateEnum::MainMenu;
	ActualState = StateEnum::MainMenu;
	dt = gameData->dtClock;
}

void StateManager::Init() {
	switch (ActualState){
		case StateEnum::MainMenu:
			mainMenuState.Init();
			break;
		case StateEnum::Game:
			gameState.Init();
			break;
		case StateEnum::GameOverMenu:
			gameOverState.Init();
			break;
		case StateEnum::PauseMenu:
			pauseState.Init();
			break;
	}
}

void StateManager::HandleInput() {
	switch (ActualState) {
		case StateEnum::MainMenu:
			mainMenuState.HandleInput();
			break;
		case StateEnum::Game:
			gameState.HandleInput();
			break;
		case StateEnum::GameOverMenu:
			gameOverState.HandleInput();
			break;
		case StateEnum::PauseMenu:
			pauseState.HandleInput();
			break;
	}
}

void StateManager::Update() {
	switch (ActualState) {
		case StateEnum::MainMenu:
			mainMenuState.Update();
			break;
		case StateEnum::Game:
			gameState.Update();
			break;
		case StateEnum::GameOverMenu:
			gameOverState.Update();
			break;
		case StateEnum::PauseMenu:
			pauseState.Update();
			break;
	}
}

void StateManager::Draw(float dt) {
	switch (ActualState) {
		case StateEnum::MainMenu:
			mainMenuState.Draw(dt);
			break;
		case StateEnum::Game:
			gameState.Draw(dt);
			break;
		case StateEnum::GameOverMenu:
			gameOverState.Draw(dt);
			break;
		case StateEnum::PauseMenu:
			pauseState.Draw(dt);
			break;
	}
}

void StateManager::ComeFromGameOver() {
	if ((LastState == StateEnum::GameOverMenu && ActualState == StateEnum::Game) || LastState == StateEnum::MainMenu)
		gameState = GameState(data);
}