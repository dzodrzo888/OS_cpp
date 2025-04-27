#include "Screen.h"
#include "Memory.h"
#include "Math.h"
#include <iostream>
#include <cstdint>
#include <stdio.h>



Screen::Screen() : memory(TOTAL_WORDS) {
    initialize_grid();
}

void Screen::display_screen() {

    freopen("file.txt", "w", stdout);
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
            int pixelIndex = y * SCREEN_WIDTH + x;
            int wordIndex = pixelIndex / WORD_SIZE;
            int bitIndex = pixelIndex % WORD_SIZE;

            bool pixelOn = (memory.ram[wordIndex] >> (15 - bitIndex)) & 1;
            if(clear_screen) {
                std::cout << ('.');
            } 
            else {
                std::cout << (pixelOn ? '#' : '.');
            }
        }
        std::cout << '\n';
    }

    fflush(stdout);
    fclose(stdout);

    freopen("/dev/tty", "w", stdout);
}

void Screen::draw_pixel(int x, int y, bool b) {
    int address = 32*y + x/16;
    int value = memory.peek(address);
    int bitIndex = 15 - (x % 16); 
    set_color(b);
    value = value | (color << bitIndex); 
    memory.poke(address, value);
}

void Screen::draw_line(int x1, int y1, int x2, int y2) {
    int sx = 0;
    int sy = 0;
    int err = 0;
    int e2 = 0;
    int dx = math.abs(x2 - x1);
    int dy = math.abs(y2 - y1);
    if(x1<x2) {
		sx = 1;
	}
	else {
		sx = -1;
	}
		
	if(y1<y2) {
		sy = 1;
	}
	else {
		sy = -1;
	}

    err = dx-dy;

    while(!((x1 == x2) && (y1 == y2))) {
        draw_pixel(x1, y1, true);
        e2 = err+err;
        if(e2 > -dy) {
			err = err-dy;
			x1 = x1+sx;
		}
			
		if(e2 < dx) {
		err = err+dx;
		y1 = y1+sy;
		}
    }
    draw_pixel(x1,y1, true);
	return;
    
}

void Screen::draw_rectangle(int x1, int y1, int x2, int y2) {
    while (y1 <= y2){
        draw_line(x1, y1, x2, y1);
        y1++;
    }
}

void Screen::draw_circle_fill(int x, int y, int r) {
    int dy = -r;
    int x1 = 0;
    int x2 = 0;
    int sqr_op = 0;
    while (dy <= r) {
        sqr_op = math.sqrt(r*r - dy*dy);
        x1 = x - sqr_op;
        x2 = x + sqr_op;
        draw_line(x1, y + dy, x2, y + dy);
        dy += 1;
    }
}

void Screen::draw_circle_unfill(int x, int y, int r) {
    int dy = -r;
    int x1 = 0;
    int x2 = 0;
    int sqr_op = 0;
    while (dy <= r) {
        sqr_op = math.sqrt(r*r - dy*dy);
        x1 = x - sqr_op;
        x2 = x + sqr_op;
        draw_pixel(x1, y + dy, true);
        draw_pixel(x2, y + dy, true);
        dy += 1;
    }
}

void Screen::set_color(bool b) {
    // Setting color for bitshifting
    if (b){
        color = 1;
        return;
    }
    color = 0;
    return;
}

void Screen::clear_screen_fnc() {
    clear_screen = true;
    display_screen();
}

void Screen::initialize_grid() {
    int row = SCREEN_WIDTH / 8;
    int col = SCREEN_HEIGHT / 16;
    int x = 0;
    int y = 0;

    for (int i = 0; i < col; i++) {
        y = i * 11;
        for (int j = 0; j < row; j++) {
            x = j * 8;
            grid_positions.push_back({x, y});
        }
    }
}

const std::vector<std::pair<int, int>>& Screen::get_grid_positions() const {
    return grid_positions;
}