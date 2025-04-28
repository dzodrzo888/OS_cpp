#include "Array.h"
#include <iostream>
#include <stdexcept>

Array::Array(Memory& memory) : memory(memory), arr(nullptr), arr_size(0) {}

Array::~Array() {
    dispose();
}

void Array::new_arr(int size) {

    arr = memory.alloc(size);
    arr_size = size;

    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

void Array::dispose() {
    if (arr) {
        memory.dealloc(arr);
        arr = nullptr;
        arr_size = 0;
    }
}

u_int16_t& Array::operator[](int index) {
    return arr[index];
}

int Array::size() const {
    return arr_size;
}