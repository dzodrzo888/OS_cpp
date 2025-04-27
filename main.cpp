#include "Math.h"
#include "Memory.h"
#include "Screen.h"
#include "Output.h"
#include <iostream>

int main(){
    Screen screen;
    Output output(screen);
    screen.initialize_grid();

    output.print_symbol(72, 0);
    output.print_symbol(69, 1);
    output.print_symbol(76, 2);
    output.print_symbol(76, 3);
    output.print_symbol(79, 4);
    output.print_symbol(127, 5);
    output.move_cursor(0, 4);
    screen.display_screen();
    return 0;
}