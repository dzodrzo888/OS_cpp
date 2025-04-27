#include "Math.h"
#include "Memory.h"
#include "Screen.h"
#include "Output.h"
#include <iostream>

int main(){
    Screen screen;
    Output output(screen);
    screen.initialize_grid();

    output.print_string("Hello");
    screen.display_screen();
    return 0;
}