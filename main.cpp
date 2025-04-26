#include "Math.h"
#include "Memory.h"
#include <iostream>

int main(){
    Memory memory(1024);
    int* block_one = memory.alloc(5);
    memory.dealloc(block_one);
    int* block_two = memory.alloc(7);
    memory.dealloc(block_two);
    int* block_three = memory.alloc(9);
    memory.dealloc(block_three);
    int* block_four = memory.alloc(3);
    memory.dealloc(block_four);
    int* block_five = memory.alloc(12);
    memory.dealloc(block_five);
    int* block_six = memory.alloc(100);
    memory.dealloc(block_six);
    memory.list_lists();
    return 0;
}