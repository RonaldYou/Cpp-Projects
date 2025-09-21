#include "include/memory-manager.h"

int main(){
    MemoryManager memManager = MemoryManager(1024); // 1KB memory pool

    void* ptr1 = memManager.allocate(256);
    void* ptr2 = memManager.allocate(512);
    void* ptr3 = memManager.allocate(300); // Should fail, not enough memory

    memManager.deallocate(ptr1);
    void* ptr4 = memManager.allocate(128); // Should succeed

    return 0;
}