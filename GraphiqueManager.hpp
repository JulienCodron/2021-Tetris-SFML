#pragma once
#include <map>
#include <SFML/Graphics.hpp>

class GraphiqueManager {
private:
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
public:
	GraphiqueManager() {}

	void LoadTexture(std::string name, std::string fileName);
	sf::Texture &GetTexture(std::string name);

	void LoadFont(std::string name, std::string fileName);
	sf::Font &GetFont(std::string name);
};