#pragma once
#include <stdio.h>
#include "GameData.hpp"
#include "StateManager.hpp"


class FrameManager {
	protected:
		float dt;
		GameData* data;
		StateManager state_m;
		
	public:
		FrameManager(int width, int length, std::string Title);
		~FrameManager();
		void Run();
		void UpdateDt();
};