#include "GraphiqueManager.hpp"

void GraphiqueManager::LoadTexture(std::string name, std::string fileName) {
	sf::Texture tex;
	if (tex.loadFromFile(fileName)) {
		textures[name] = tex;
	}
}

sf::Texture &GraphiqueManager::GetTexture(std::string name) {
	return textures.at(name);
}

void GraphiqueManager::LoadFont(std::string name, std::string fileName) {
	sf::Font font;
	if (font.loadFromFile(fileName)) {
		fonts[name] = font;
	}
}

sf::Font &GraphiqueManager::GetFont(std::string name) {
	return fonts.at(name);
}