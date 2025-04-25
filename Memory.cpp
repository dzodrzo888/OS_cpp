#include "Memory.h"
#include <iostream>

Memory::Memory(int heapBase) : ram(heapBase, 0) {
    //Initialize the head of the free list
    freeListHead = new FreeList;

    // set the params of the first freelist.
    // Substract 2 becasue 2 spaces of ram belong to the next pointer and heapbase size
    freeListHead->Next = nullptr;
    freeListHead->size = heapBase - 2;
    freeListHead->start = 0;

    std::cout << "Initialized FreeList with heap size: " << heapBase << std::endl;
}

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

int* Memory::alloc(int size) {
    FreeList* curr_list = freeListHead;

    while (curr_list != nullptr) {
        if (curr_list->size > size + 2) {
            curr_list->size -= (size + 2);
            int alloc_start = curr_list->start + curr_list->size;
            
            ram[alloc_start] = NULL;             
            ram[alloc_start + 1] = size;      
            
            return &ram[alloc_start + 2];  
        }

        curr_list = curr_list->Next;
    }

    return nullptr; 
}


void Memory::dealloc(int* o) {
    int* ram_ptr = ram.data();
    int block_start = o - ram_ptr - 2;
    
}