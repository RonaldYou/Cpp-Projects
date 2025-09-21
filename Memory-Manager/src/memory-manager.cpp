#include "memory-manager.h"

MemoryManager::MemoryManager(size_t totalSize) : totalSize(totalSize), usedSize(0), blocks(nullptr){
    blocks = new MemoryBlock[totalSize / sizeof(MemoryBlock)];
    for(size_t i = 0; i < totalSize / sizeof(MemoryBlock); ++i){
        blocks[i].id = -1;
        blocks[i].size = 0;
        blocks[i].ptr = nullptr;
    }
}

MemoryManager::~MemoryManager(){
    delete [] blocks;
}

void* MemoryManager::allocate(size_t size){
    if(usedSize + size > totalSize){
        return nullptr; // Not enough memory
    }

    for(size_t i = 0; i < totalSize / sizeof(MemoryBlock); ++i){
        if(blocks[i].id == -1){ // Free block
            blocks[i].id = static_cast<int>(i);
            blocks[i].size = size;
            blocks[i].ptr = ::operator new(size);
            usedSize += size;
            return blocks[i].ptr;
        }
    }
    return nullptr; // No free block found   
}

void MemoryManager::deallocate(void* ptr){
    for(size_t i = 0; i < totalSize / sizeof(MemoryBlock); ++i){
        if(blocks[i].ptr == ptr){
            usedSize -= blocks[i].size;
            ::operator delete(blocks[i].ptr);
            blocks[i].id = -1;
            blocks[i].size = 0;
            blocks[i].ptr = nullptr;
            return;
        }
    }
    return;
}

size_t MemoryManager::getTotalSize() const{
    return totalSize;
}

size_t MemoryManager::getUsedSize() const{
    return usedSize;
}
