#ifndef MEMORY_H
#define MEMORY_H
#include <unordered_map>
#include <iostream>
#include <vector>

class Memory {
public:

    Memory(int heapBase);

    int peek(int address);
    void poke(int address, int value);
    int* alloc(int size);
    void dealloc(int* o);
    void list_lists();
private:
    std::vector<int> ram;
    struct FreeList
    {
        FreeList* Next;
        int size;
        int start;
    };
    FreeList* freeListHead;
};

#endif
