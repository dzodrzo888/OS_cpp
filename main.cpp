#include "Math.h"
#include "Memory.h"
#include "Screen.h"
#include <iostream>

int main(){
    Screen screen;
    screen.draw_rectangle(5, 2, 10, 7);
    screen.display_screen();
    screen.clear_screen_fnc();
    return 0;
}