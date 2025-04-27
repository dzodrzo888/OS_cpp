#ifndef OUTPUT_H
#define OUTPUT_H
#include <iostream>
#include <vector>
#include "Screen.h"

class Output {

public:
    Output(Screen& screen);

    void create(int index, int a, int b, int c, int d, int e,
		         int f, int g, int h, int i, int j, int k);
    void print_symbol(int index, int position);
    
private:
    std::vector<std::vector<int>> char_maps;
    Screen& screen;
    const std::vector<std::pair<int, int>>& grid_positions;
};


#endif