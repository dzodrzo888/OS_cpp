#ifndef ARRAY_H
#define ARRAY_H
#include "Memory.h"
#include <iostream>

class Array {
public:
    Array(Memory& memory); 
    ~Array();             

    void new_arr(int size); 
    void dispose();         
    u_int16_t& operator[](int index); 
    int size() const;      

private:
    Memory& memory;         
    u_int16_t* arr;         
    int arr_size;           
};

#endif