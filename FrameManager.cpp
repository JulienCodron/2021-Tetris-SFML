#include "FrameManager.hpp"
#include "MainMenuState.hpp"

GameData::GameData() {
};


void GameData::Init() {
    assets = GraphiqueManager();
    clic = ClicManager();
    ActualState = new MainMenuState(this);
}

FrameManager::FrameManager(int width, int length, std::string Title){
    data = new GameData();
    data->Init();
    data->ActualState->Init();
	data->window.create(sf::VideoMode(width, length), Title,sf::Style::Close);
    data->dtClock.restart().asSeconds();
    Run();
};


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
        data->ActualState->Update();
        data->ActualState->Draw(dt);
    }
}