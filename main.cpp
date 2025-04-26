#include "Math.h"
#include "Memory.h"
#include "Screen.h"
#include <iostream>

int main(){
    Screen screen;
    screen.draw_circle_unfill(10, 10, 3);
    screen.display_screen();
    return 0;
}