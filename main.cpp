#include "Math.h"
#include "Memory.h"
#include "Screen.h"
#include "Output.h"
#include "String.h"
#include <iostream>

int main(){
    String str(5);

    str.set_char_at(0, 'H');
    str.set_char_at(1, 'e');
    str.set_char_at(2, 'l');
    str.set_char_at(3, 'l');
    str.set_char_at(4, 'o');

    std::string string = str.append_char('!');

    std::cout << "String: " << string << "\n";

    return 0;
}