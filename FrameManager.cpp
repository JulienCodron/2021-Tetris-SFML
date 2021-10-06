#include "FrameManager.hpp"


FrameManager::FrameManager(int width, int length, std::string Title){
	this->window.create(sf::VideoMode(width, length), Title,sf::Style::Close);
    this->dtClock.restart().asSeconds();
    this->Run();
};

void FrameManager::UpdateDt() {
    /* update dt at each frame*/
    this->dt = this->dtClock.restart().asSeconds();
};

void FrameManager::Run(){
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        this->UpdateDt();
        while (window.pollEvent(this->ev))
        {
            switch(this->ev.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    this->ActualState->HandleInput();

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