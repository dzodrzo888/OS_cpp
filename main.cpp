#include "Math.h"
#include "Memory.h"
#include <iostream>

int main(){
    Memory memory(1024);
    int* block = memory.alloc(5);
    memory.dealloc(block);
    return 0;
}