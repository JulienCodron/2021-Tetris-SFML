#include "FrameManager.hpp"

FrameManager::FrameManager(int width, int length, std::string Title){
    data = new GameData();
    state_m = StateManager(data);
	data->window.create(sf::VideoMode(width, length), Title,sf::Style::Close);
    data->dtClock.restart().asSeconds();
    Run();
}

FrameManager::~FrameManager() {
    //free memory
    delete data;
}


void FrameManager::UpdateDt() {
    // update delta time
    dt = data->dtClock.restart().asMilliseconds();
}

void FrameManager::Run(){
    //gameloop
    while (data->window.isOpen())
    {
        //Check if the state change and change it
        if (data->ActualState != state_m.ActualState) {
            state_m.LastState = state_m.ActualState;
            state_m.ActualState = data->ActualState;
            state_m.ComeFromGameOver();
        }
         
        UpdateDt();
        while (data->window.pollEvent(data->ev))
        {
            state_m.HandleInput();
        }
        if (data->window.isOpen()) {
            state_m.Update();
            state_m.Draw(dt);
        }
    }
}