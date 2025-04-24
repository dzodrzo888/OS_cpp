#include "Memory.h"
#include <iostream>

int Memory::peek(int address) {
    int value = ram[address];
    return value;
}
void Memory::poke(int address, int value){
    ram[address] = value;
}
