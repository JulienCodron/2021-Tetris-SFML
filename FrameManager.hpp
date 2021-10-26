#pragma once
#include <stdio.h>
#include "GameData.hpp"


class FrameManager {
	protected:
		float dt;
		GameData* data;
		
	public:
		FrameManager(int width, int length, std::string Title);
		~FrameManager();
		void Run();
		void UpdateDt();
};