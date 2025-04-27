#include "Math.h"
#include "Memory.h"
#include "Screen.h"
#include <iostream>

int main(){
    Screen screen;
    screen.initialize_grid();
    const auto& grid_positions = screen.get_grid_positions();

    for (const auto& position : grid_positions) {
        std::cout << "(" << position.first << ", " << position.second << ")\n";
    }
    return 0;
}