#pragma once
#include "SFML\Graphics.hpp"

// Wanna do clicable button for menu, but finally i didn't implement them
class ClicManager
{
public:
	ClicManager() {}
	~ClicManager() {}

	bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);
	sf::Vector2i GetMousePosition(sf::RenderWindow& window);
};
