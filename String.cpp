#include "String.h"
#include <iostream>

String::String(int max_length) : memory(heap_memory) {
    u_int16_t* empty_str = memory.alloc(max_length + 1);
    memory.ram[max_length + 1] = static_cast<u_int16_t>('\n');
}

void String::dispose() {
    memory.dealloc(empty_str);
}

int String::length() const {
    int length = 0;
    while (memory.ram[length] != static_cast<u_int16_t>('\n')) {
        length++;
    }
    return length;
}

char String::char_at(int j) {
    u_int16_t* ram_ptr = memory.ram.data();
    int block_start = empty_str - ram_ptr;
    char c = memory.ram[block_start + j];
    return c;
}

void String::set_char_at(int j, char c) {
    u_int16_t* ram_ptr = memory.ram.data();
    int block_start = empty_str - ram_ptr;
    memory.ram[block_start + j] = c;
    return;
}