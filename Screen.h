#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <cstdint>

class Screen {
public:
    void display_screen();
    void clear_screen();
    void set_color(bool b);
    void draw_pixel(int x, int y);
    void draw_line(int x1, int y1, int x2, int y2);
    void draw_rectangle(int x1, int y1, int x2, int y2);
    void draw_circle(int x, int y, int r);
private:
    static const int SCREEN_WIDTH = 512;
    static const int SCREEN_HEIGHT = 256;
    static const int WORD_SIZE = 16;
    static const int TOTAL_WORDS = (SCREEN_WIDTH * SCREEN_HEIGHT) / WORD_SIZE;
    static uint16_t screen[TOTAL_WORDS];
};

#endif