#include "MemoryManager.hpp"

// I try to implement a basic Stack Manager that i finally didn't use it 

MemoryManager::MemoryManager() {}

void MemoryManager::Init(size_t size) {
    // Construct the allocator
    if (memory_ptr != nullptr) {
        free(memory_ptr);
    }
    memory_ptr = malloc(size);
    marker = 0;
}

size_t MemoryManager::getMarker() {
    // Get a marker to the current top
    return marker;
}

void* MemoryManager::alloc(size_t size) {
    // Allocates a new block from the top
    const std::size_t nextAddress = (size_t)memory_ptr + marker;
    if (sizeof((void*)nextAddress) + size > total_size) {
        return nullptr;
    }
    marker += size;
    total_size -= size;
    void* g = (void*)nextAddress;
    return g;
}

void MemoryManager::freeToMarker(size_t newMarker) {
    //Rolls the stack back to a previous marker
    total_size += newMarker;
    marker -= newMarker;
}

void MemoryManager::clear() {
    // Clear the whole stack
    total_size += marker;
    marker = 0;
}

MemoryManager::~MemoryManager() {
    free(memory_ptr);
}