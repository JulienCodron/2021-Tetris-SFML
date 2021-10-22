#pragma once
#include <cstdint>
#include <corecrt_malloc.h>

class MemoryManager{

private:
	void* memory_ptr = nullptr;
	size_t total_size;
	size_t marker;

public:
	explicit MemoryManager(size_t size);
	~MemoryManager();
	size_t getMarker();
	void* alloc(size_t size);
	void freeToMarker(size_t marker);
	void memoryLeft();
	void clear();
};