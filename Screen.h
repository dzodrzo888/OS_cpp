#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <cstdint>
#include "Memory.h"
#include "Math.h"

class Screen {
public:

    Screen();

    void display_screen();
    void clear_screen_fnc();
    void set_color(bool b);
    void draw_pixel(int x, int y, bool b);
    void draw_line(int x1, int y1, int x2, int y2);
    void draw_rectangle(int x1, int y1, int x2, int y2);
    void draw_circle_fill(int x, int y, int r);
    void draw_circle_unfill(int x, int y, int r);
    void initialize_grid();
    const std::vector<std::pair<int, int>>& get_grid_positions() const;

private:
    static const int SCREEN_WIDTH = 512;
    static const int SCREEN_HEIGHT = 256;
    static const int WORD_SIZE = 16;
    static const int TOTAL_WORDS = (SCREEN_WIDTH * SCREEN_HEIGHT) / WORD_SIZE;
    std::vector<std::pair<int, int>> grid_positions;
    Memory memory;
    Math math;
    int color = 0;
    bool clear_screen = false;
};

#endif