#pragma once
#include "State.hpp"
#include "FrameManager.hpp"
#include <SFML/Graphics.hpp>

class MainMenuState : public State {
private:
	GameData *data;
	sf::Sprite background;
	sf::Sprite title;

public:

	MainMenuState(GameData *gameData);
	~MainMenuState();
	void Init();
	void HandleInput();
	void Update();
	void Draw(float dt);
};