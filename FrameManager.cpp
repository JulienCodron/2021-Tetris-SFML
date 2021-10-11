#include "FrameManager.hpp"
#include "MainMenuState.hpp"

GameData::GameData() {
    assets = new GraphiqueManager();
    clic = new ClicManager();
    ActualState = new MainMenuState(this);
};

GameData::~GameData() {
    delete assets;
    delete clic;
    delete ActualState;
};

FrameManager::FrameManager(int width, int length, std::string Title){
    data = new GameData();
	data->window.create(sf::VideoMode(width, length), Title,sf::Style::Close);
    data->dtClock.restart().asSeconds();
    data->ActualState->Init();
    Run();
};

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
        data->ActualState->Update();
        data->ActualState->Draw(dt);
    }
}