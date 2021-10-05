#include "Tetris.hpp"
#include "MainMenu.hpp"


Tetris::Tetris(int width, int length, std::string Title){
	this->window.create(sf::VideoMode(width, length), Title,sf::Style::Close);
    this->Run();
};

void Tetris::Run(){
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (window.pollEvent(this->ev))
        {
            switch(this->ev.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    if (this->ev.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;

                default:
                    break;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

Tetris::~Tetris() {
    
};
