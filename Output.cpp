#include "Output.h"
#include <iostream>
#include <vector>
#include <string>

Output::Output(Screen& screen) : screen(screen), grid_positions(screen.get_grid_positions()) {

    create(0,12,30,51,51,51,51,51,30,12,0,0); // 0
    create(1,12,14,15,12,12,12,12,12,63,0,0); // 1
    create(2,30,51,48,24,12,6,3,51,63,0,0);   // 2
    create(3,30,51,48,48,28,48,48,51,30,0,0); // 3
    create(4,16,24,28,26,25,63,24,24,60,0,0); // 4
    create(5,63,3,3,31,48,48,48,51,30,0,0);   // 5
    create(6,28,6,3,3,31,51,51,51,30,0,0);    // 6
    create(7,63,49,48,48,24,12,12,12,12,0,0); // 7
    create(8,30,51,51,51,30,51,51,51,30,0,0); // 8
    create(9,30,51,51,51,62,48,48,24,14,0,0); // 9

    create(32,0,0,0,0,0,0,0,0,0,0,0);          //
    create(33,12,30,30,30,12,12,0,12,12,0,0);  // !
    create(34,54,54,20,0,0,0,0,0,0,0,0);       // "
    create(35,0,18,18,63,18,18,63,18,18,0,0);  // #
    create(36,12,30,51,3,30,48,51,30,12,12,0); // $
    create(37,0,0,35,51,24,12,6,51,49,0,0);    // %
    create(38,12,30,30,12,54,27,27,27,54,0,0); // &
    create(39,12,12,6,0,0,0,0,0,0,0,0);        // '
    create(40,24,12,6,6,6,6,6,12,24,0,0);      // (
    create(41,6,12,24,24,24,24,24,12,6,0,0);   // )
    create(42,0,0,0,51,30,63,30,51,0,0,0);     // *
    create(43,0,0,0,12,12,63,12,12,0,0,0);     // +
    create(44,0,0,0,0,0,0,0,12,12,6,0);        // ,
    create(45,0,0,0,0,0,63,0,0,0,0,0);         // -
    create(46,0,0,0,0,0,0,0,12,12,0,0);        // .    
    create(47,0,0,32,48,24,12,6,3,1,0,0);      // /
        
    create(58,0,0,12,12,0,0,12,12,0,0,0);      // :
    create(59,0,0,12,12,0,0,12,12,6,0,0);      // ;
    create(60,0,0,24,12,6,3,6,12,24,0,0);      // <
    create(61,0,0,0,63,0,0,63,0,0,0,0);        // =
    create(62,0,0,3,6,12,24,12,6,3,0,0);       // >
    create(63,30,51,51,24,12,12,0,12,12,0,0);  // ?
    create(64,30,51,51,59,59,59,27,3,30,0,0);  // @

    create(65,12,30,51,51,63,51,51,51,51,0,0); // A
    create(66,31,51,51,51,31,51,51,51,31,0,0); // B
    create(67,28,54,35,3,3,3,35,54,28,0,0);    // C
    create(68,15,27,51,51,51,51,51,27,15,0,0); // D
    create(69,63,51,35,11,15,11,35,51,63,0,0); // E
    create(70,63,51,35,11,15,11,3,3,3,0,0);    // F
    create(71,28,54,35,3,59,51,51,54,44,0,0);  // G
    create(72,51,51,51,51,63,51,51,51,51,0,0); // H
    create(73,30,12,12,12,12,12,12,12,30,0,0); // I
    create(74,60,24,24,24,24,24,27,27,14,0,0); // J
    create(75,51,51,51,27,15,27,51,51,51,0,0); // K
    create(76,3,3,3,3,3,3,35,51,63,0,0);       // L
    create(77,33,51,63,63,51,51,51,51,51,0,0); // M
    create(78,51,51,55,55,63,59,59,51,51,0,0); // N
    create(79,30,51,51,51,51,51,51,51,30,0,0); // O
    create(80,31,51,51,51,31,3,3,3,3,0,0);     // P
    create(81,30,51,51,51,51,51,63,59,30,48,0);// Q
    create(82,31,51,51,51,31,27,51,51,51,0,0); // R
    create(83,30,51,51,6,28,48,51,51,30,0,0);  // S
    create(84,63,63,45,12,12,12,12,12,30,0,0); // T
    create(85,51,51,51,51,51,51,51,51,30,0,0); // U
    create(86,51,51,51,51,51,30,30,12,12,0,0); // V
    create(87,51,51,51,51,51,63,63,63,18,0,0); // W
    create(88,51,51,30,30,12,30,30,51,51,0,0); // X
    create(89,51,51,51,51,30,12,12,12,30,0,0); // Y
    create(90,63,51,49,24,12,6,35,51,63,0,0);  // Z

    create(91,30,6,6,6,6,6,6,6,30,0,0);          // [
    create(92,0,0,1,3,6,12,24,48,32,0,0);        // '\'
    create(93,30,24,24,24,24,24,24,24,30,0,0);   // ]
    create(94,8,28,54,0,0,0,0,0,0,0,0);          // ^
    create(95,0,0,0,0,0,0,0,0,0,63,0);           // _
    create(96,6,12,24,0,0,0,0,0,0,0,0);          // `

    create(97,0,0,0,14,24,30,27,27,54,0,0);      // a
    create(98,3,3,3,15,27,51,51,51,30,0,0);      // b
    create(99,0,0,0,30,51,3,3,51,30,0,0);        // c
    create(100,48,48,48,60,54,51,51,51,30,0,0);  // d
    create(101,0,0,0,30,51,63,3,51,30,0,0);      // e
    create(102,28,54,38,6,15,6,6,6,15,0,0);      // f
    create(103,0,0,30,51,51,51,62,48,51,30,0);   // g
    create(104,3,3,3,27,55,51,51,51,51,0,0);     // h
    create(105,12,12,0,14,12,12,12,12,30,0,0);   // i
    create(106,48,48,0,56,48,48,48,48,51,30,0);  // j
    create(107,3,3,3,51,27,15,15,27,51,0,0);     // k
    create(108,14,12,12,12,12,12,12,12,30,0,0);  // l
    create(109,0,0,0,29,63,43,43,43,43,0,0);     // m
    create(110,0,0,0,29,51,51,51,51,51,0,0);     // n
    create(111,0,0,0,30,51,51,51,51,30,0,0);     // o
    create(112,0,0,0,30,51,51,51,31,3,3,0);      // p
    create(113,0,0,0,30,51,51,51,62,48,48,0);    // q
    create(114,0,0,0,29,55,51,3,3,7,0,0);        // r
    create(115,0,0,0,30,51,6,24,51,30,0,0);      // s
    create(116,4,6,6,15,6,6,6,54,28,0,0);        // t
    create(117,0,0,0,27,27,27,27,27,54,0,0);     // u
    create(118,0,0,0,51,51,51,51,30,12,0,0);     // v
    create(119,0,0,0,51,51,51,63,63,18,0,0);     // w
    create(120,0,0,0,51,30,12,12,30,51,0,0);     // x
    create(121,0,0,0,51,51,51,62,48,24,15,0);    // y
    create(122,0,0,0,63,27,12,6,51,63,0,0);      // z
        
    create(123,56,12,12,12,7,12,12,12,56,0,0);   // {
    create(124,12,12,12,12,12,12,12,12,12,0,0);  // |
    create(125,7,12,12,12,56,12,12,12,7,0,0);    // }
    create(126,38,45,25,0,0,0,0,0,0,0,0);        // ~
    create(127,63,63,63,63,63,63,63,63,63,0,0); // Cursor

    return;
}

void Output::create(int index, int a, int b, int c, int d, int e,
		         int f, int g, int h, int i, int j, int k)
{
    int char_maps_size = char_maps.size();
    if (index >= char_maps_size) {
        char_maps.resize(index + 1);
    }

    char_maps[index] = {a, b, c, d, e, f, g, h, i, j, k};

    return;

}

void Output::print_symbol(int index, int position) {
    if(index == 127) {
        cursor_position = position + 1;
    }
    auto& char_cor = char_maps[index]; // Get the bitmap for the character
    int start_x = grid_positions[position].first; // Starting x position
    int start_y = grid_positions[position].second; // Starting y position

    for (int i = 0; i < 11; i++) { // Iterate over 11 rows
        int row_data = char_cor[i]; // Get the row data (integer)
        for (int j = 0; j < 8; j++) { // Iterate over 8 columns
            bool b = (row_data >> j) & 1; // Extract the bit (1 = on, 0 = off)
            if (b) {
                screen.draw_pixel(start_x + j, start_y + i, true); // Draw "on" pixel
            } else {
                screen.draw_pixel(start_x + j, start_y + i, false); // Draw "off" pixel (optional)
            }
        }
    }
}

void Output::move_cursor(int position) {
    int grid_size = grid_positions.size();
    if (position > grid_size) {
        std::cout << "Position not present in the Grid!" << "\n";
        return;
    }
    if(cursor_position != -1) {
        print_symbol(32, cursor_position);
    }
    print_symbol(127, position);
}

void Output::advance_char(char c) {
    int position = 0;
    if(last_symb_pos != -1) {
        last_symb_pos++;
        position = last_symb_pos;
    }
    else {
        last_symb_pos = 0;
    }
    print_symbol(static_cast<int>(c), position);
    move_cursor(position + 1);
}

void Output::advance_int(int i) {
    int position = 0;
    if(last_symb_pos != -1) {
        last_symb_pos++;
        position = last_symb_pos;
    }
    else {
        last_symb_pos = 0;
    }
    print_symbol(i, position);
    move_cursor(position + 1);
}

void Output::print_string(std::string str) {
    int len_of_str = str.length();
    for(int i = 0; i < len_of_str; i++) {
        advance_char(str[i]);
    }
}

void Output::println() {
    int row_pos = cursor_position / 11;
    move_cursor(row_pos * 11);
}