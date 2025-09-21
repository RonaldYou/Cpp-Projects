#ifndef MEMORY_BLOCK_H
#define MEMORY_BLOCK_H

#include <cstddef>

struct MemoryBlock{
    int id;
    size_t size;
    void* ptr;
};

#endif // MEMORY_BLOCK_H