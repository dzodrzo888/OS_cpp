#include "String.h"
#include <iostream>

String::String(int max_length) : memory(heap_memory) {
    empty_str = memory.alloc(max_length + 1);
    for(int i = 0; i <= max_length; i++) {
        memory.ram[i] = static_cast<u_int16_t>('\0');
    }
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

void String::erase_last_char() {
    int length = this->length();
    memory.ram[block_start + length - 1] = static_cast<u_int16_t>('\0');
}

int String::int_value() {
    int val = 0;
    for(int i =0; i < this->length() && memory.ram[block_start + i] < 58; i++) {
        int d = memory.ram[block_start + i];
        val = val * 10 + d - 48;
    }
    return val;
}

void String::set_int(int number) {
    clear();
    std::string str = int_to_str(number); 
    for (size_t i = 0; i < str.length(); i++) {
        memory.ram[block_start + i] = static_cast<u_int16_t>(str[i]);
    }
    memory.ram[block_start + str.length()] = static_cast<u_int16_t>('\0'); 
}

std::string String::int_to_str(int number) {
    if (number == 0) {
        return "";
    }
    int last_digit = number % 10;
    char c = static_cast<char>('0' + last_digit); 
    return int_to_str(number / 10) + c; 
}

void String::clear() {
    int max_length = memory.ram[block_start - 1];
    for (int i = 0; i < max_length; i++) {
        memory.ram[block_start + i] = static_cast<u_int16_t>('\0');
    }
}

char String::new_line() {
    return '\n';
}

char String::backspace() {
    return '\b';
}

char String::double_quote() {
    return '"';
}