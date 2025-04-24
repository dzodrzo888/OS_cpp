#include "BinaryOp.h"
#include <iostream>
#include <bitset>
#include <cstring>
#include <string>

std::string BinaryOp::get_binary(int x) {
    // Convert integers to 16-bit binary strings
    std::string binary_x = std::bitset<16>(x).to_string();

    // Calculate the lengths of the binary strings
    int len_x = binary_len(binary_x);

    // Adjust binary strings based on lengths
    binary_x = binary_x.substr(len_x);

    // Return both binary strings as a pair
    return binary_x;
}

int BinaryOp::binary_len(const std::string& str) {
    if (str == "0") return 1; // Handle special case for "0"
    int lenght = 0;

    // Loop until we find '1' or reach the end of the string
    while (lenght < str.size() && str[lenght] != '1') {
        lenght++;
    }

    return lenght;
}