#ifndef MEMORY_H
#define MEMORY_H

class Memory {
public:
    int peek(int address);
    void poke(int address, int value);
    int* alloc(int size);
    void dealloc(int* o);
private:
    int ram;
};

#endif
