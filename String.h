#ifndef STRING_H
#define STRING_H
#include "Memory.h"
#include <iostream>

class String {

public:
    String(int max_length);
    
    void dispose();
    int length() const;
    char char_at(int j);
    void set_char_at(int j, char c);
    std::string append_char(char c);
    void erase_last_char();
    int int_value();
    void set_int(int number);
    std::string int_to_str(int number);
    char new_line();
    char backspace();
    char double_quote();
    
private:
    Memory memory;
    int heap_memory = 1024;
    u_int16_t* empty_str;
    int block_start;
    void clear();
};

#endif