#include "ClicManager.hpp"

// Wanna do clicable button for menu, but finally i didn't implement them
bool ClicManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window){
	if (sf::Mouse::isButtonPressed(button)){
		sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

		if (playButtonRect.contains(sf::Mouse::getPosition(window))){
			return true;
		}
	}

	return false;
}

sf::Vector2i ClicManager::GetMousePosition(sf::RenderWindow &window){
	return sf::Mouse::getPosition(window);
}
