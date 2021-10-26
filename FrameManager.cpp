#include "FrameManager.hpp"
#include "MainMenuState.hpp"
#include <iostream>

FrameManager::FrameManager(int width, int length, std::string Title){
    data = new GameData();
    data->ActualState = new MainMenuState(data);
    data->ActualState->Init();
	data->window.create(sf::VideoMode(width, length), Title,sf::Style::Close);
    data->dtClock.restart().asSeconds();
    Run();
}

FrameManager::~FrameManager() {
    delete data;
}


void FrameManager::UpdateDt() {
    dt = data->dtClock.restart().asSeconds();
}

void FrameManager::Run(){
    while (data->window.isOpen())
    {
        UpdateDt();
        while (data->window.pollEvent(data->ev))
        {
            data->ActualState->HandleInput();
        }
        if (data->window.isOpen()) {
            data->ActualState->Update();
            data->ActualState->Draw(dt);
        }
    }
}