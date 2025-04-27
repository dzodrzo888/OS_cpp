#include "Math.h"
#include "Memory.h"
#include "Screen.h"
#include "Output.h"
#include <iostream>

int main(){
    Screen screen;
    Output output(screen);
    screen.initialize_grid();

    output.advance_int(1);
    output.advance_int(2);
    output.advance_int(3);
    output.advance_int(4);
    output.advance_char('H');
    output.advance_char('I');
    output.advance_int(5);
    screen.display_screen();
    return 0;
}