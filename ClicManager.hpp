#pragma once
#include "SFML\Graphics.hpp"

class ClicManager
{
public:
	ClicManager() {}
	~ClicManager() {}

	bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);
	sf::Vector2i GetMousePosition(sf::RenderWindow& window);
};
