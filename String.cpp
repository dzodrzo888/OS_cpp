#include "String.h"
#include <iostream>

String::String(int max_length) : memory(heap_memory) {
    empty_str = memory.alloc(max_length + 1);
    memory.ram[max_length + 1] = static_cast<u_int16_t>('\0');
    u_int16_t* ram_ptr = memory.ram.data();
    block_start = empty_str - ram_ptr;
}

void String::dispose() {
    memory.dealloc(empty_str);
}

int String::length() const {
    int length = 0;
    while (memory.ram[block_start + length] != static_cast<u_int16_t>('\0')) {
        length++;
    }
    return length;
}

char String::char_at(int j) {
    return static_cast<char>(memory.ram[block_start + j]);
}

void String::set_char_at(int j, char c) {
    memory.ram[block_start + j] = static_cast<u_int16_t>(c);
    return;
}

std::string String::append_char(char c) {
    int length = this->length();

    memory.ram[block_start + length] = c;
    memory.ram[block_start + length + 1] = static_cast<u_int16_t>('\0');
    
    std::string result;
    for (int i = 0; i <= length; i++) {
        result += static_cast<char>(memory.ram[block_start + i]);
    }

    return result;
}