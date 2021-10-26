#include "GameData.hpp"

GameData::GameData() {
	//memory_m = MemoryManager(MEMORY_ALLOCATED);
	assets = GraphiqueManager();
	clic = ClicManager();
}

GameData::~GameData() {
	delete ActualState;
}
