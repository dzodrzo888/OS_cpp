#include "Screen.h"
#include "Memory.h"
#include <iostream>
#include <cstdint>

Screen::Screen() : memory(TOTAL_WORDS) {

}

void Screen::display_screen() {
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
            int pixelIndex = y * SCREEN_WIDTH + x;
            int wordIndex = pixelIndex / WORD_SIZE;
            int bitIndex = pixelIndex % WORD_SIZE;

            bool pixelOn = (memory.ram[wordIndex] >> (15 - bitIndex)) & 1;
            std::cout << (pixelOn ? '#' : '.');
        }
        std::cout << '\n';
    }
}