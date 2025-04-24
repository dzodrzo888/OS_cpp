#ifndef MEMORY_H
#define MEMORY_H
#include <unordered_map>
#include <iostream>

class Memory {
public:
    int peek(int address);
    void poke(int address, int value);
    int* alloc(int size);
    void dealloc(int* o);
private:
    std::unordered_map<int, int> ram;
};

#endif
