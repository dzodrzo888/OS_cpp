#ifndef MEMORY_H
#define MEMORY_H
#include <unordered_map>
#include <iostream>
#include <vector>
#include <cstdint>

class Memory {
public:

    Memory(unsigned short heapBase);

    int peek(int address);
    void poke(int address, int value);
    u_int16_t* alloc(int size);
    void dealloc(u_int16_t* o);
    void list_lists();

    std::vector<u_int16_t> ram;
private:
    struct FreeList
    {
        FreeList* Next;
        int size;
        int start;
    };
    FreeList* freeListHead;
};

#endif
