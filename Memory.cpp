#include "Memory.h"
#include <iostream>

int Memory::peek(int address) {
    /*
    Peek at a address in a ram
    */
    int value = ram[address];
    return value;
}
void Memory::poke(int address, int value){
    /*
    Assign a value to a specified address.
    */
    ram[address] = value;
}
