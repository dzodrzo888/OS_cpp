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

private:
    Memory memory;
    int heap_memory = 1024;
    u_int16_t* empty_str;
};

#endif