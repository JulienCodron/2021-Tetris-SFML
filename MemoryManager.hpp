#pragma once
#include <cstddef>
#include <corecrt_malloc.h>

class MemoryManager{

public:	
	void* memory_ptr = nullptr;
	size_t total_size;
	size_t marker;

	MemoryManager();
	~MemoryManager();
	void Init(size_t size);
	size_t getMarker();
	void* alloc(size_t size);
	void freeToMarker(size_t marker);
	void clear();
};