#include "String.h"
#include <iostream>

String::String(int max_length) : memory(heap_memory) {
    u_int16_t* empty_str = memory.alloc(max_length + 1);
    memory.ram;
}

void String::dispose() {
    memory.dealloc(empty_str);
}
