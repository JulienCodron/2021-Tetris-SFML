#include "MemoryManager.hpp"
#include <iostream>

MemoryManager::MemoryManager() {}

// Construct the allocator
MemoryManager::MemoryManager(size_t total_size): total_size(total_size) {
    if (memory_ptr != nullptr) {
        free(memory_ptr);
    }
    memory_ptr = malloc(total_size);
    marker = 0;
}

// Get a marker to the current top
size_t MemoryManager::getMarker() {
    return marker;
}

// Allocates a new block from the top
void* MemoryManager::alloc(size_t size) {
    const std::size_t nextAddress = (size_t)memory_ptr + marker;
    if (sizeof((void*)nextAddress) + size > total_size) {
        return nullptr;
    }
    marker += size;
    total_size -= size;
    void* g = (void*)nextAddress;
    return g;
}

// Rolls the stack back to a previous marker
void MemoryManager::freeToMarker(size_t newMarker) {
    total_size += newMarker;
    marker -= newMarker;
}

// Clear the whole stack
void MemoryManager::clear() {
    total_size += marker;
    marker = 0;
}

// Show how many space left
void MemoryManager::memoryLeft() {
    std::cout << total_size << std::endl;
}

MemoryManager::~MemoryManager() {
    free(memory_ptr);
}