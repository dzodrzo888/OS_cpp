#include "Math.h"
#include "Memory.h"
#include "Screen.h"
#include "Output.h"
#include "String.h"
#include <iostream>

int main(){
    String str(10);

    str.set_char_at(0, '1');
    str.set_char_at(1, '2');
    str.set_char_at(2, '3');

    int val = str.int_value();
    std::cout << "String_val: " << val << "\n";

    return 0;
}