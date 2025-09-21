#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "memory-block.h"

class MemoryManager {
    public:
        MemoryManager(size_t totalSize);
        ~MemoryManager();

        void* allocate(size_t size);
        void deallocate(void* ptr);
        size_t getTotalSize() const;
        size_t getUsedSize() const;

    private:
        size_t totalSize;
        size_t usedSize;
        MemoryBlock* blocks;
};

#endif // MEMORY_MANAGER_H