#include "Memory.h"
#include <iostream>

Memory::Memory(unsigned short heapBase) : ram(heapBase, static_cast<u_int16_t>(0)) {
    //Initialize the head of the free list
    freeListHead = new FreeList;

    // set the params of the first freelist.
    // Substract 2 becasue 2 spaces of ram belong to the next pointer and heapbase size
    freeListHead->Next = nullptr;
    freeListHead->size = heapBase;
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

u_int16_t* Memory::alloc(int size) {
    FreeList* curr_list = freeListHead;

    while (curr_list != nullptr) {
        if (curr_list->size > size + 2) {
            curr_list->size -= (size + 2);
            int alloc_start = curr_list->start + curr_list->size;
            
            ram[alloc_start] = 0;             
            ram[alloc_start + 1] = size;      
            return &ram[alloc_start + 2];  
        }

        curr_list = curr_list->Next;
    }
    return nullptr; 
}


void Memory::dealloc(u_int16_t* o) {
    u_int16_t* ram_ptr = ram.data();
    int block_start = o - ram_ptr - 2;
    FreeList* tail_list = freeListHead;

    while(tail_list->Next != nullptr) {
        tail_list = tail_list->Next;
    }
    
    if(tail_list == nullptr){
        std::cout << "No appropriate list found" << "\n";
        return;
    }

    FreeList* new_list = new FreeList;
    new_list->start = block_start;
    new_list->size = ram[block_start + 1];
    new_list->Next = nullptr;
    tail_list->Next = new_list;
}

void Memory::list_lists() {
    FreeList* list = freeListHead;
    while (list != nullptr)
    {
        std::cout << list->start << "  " << list->size << "  " << list->Next << "\n";
        list = list->Next;
    }
    delete list;
    return;
}