#include "Math.h"
#include "BinaryOp.h"
#include <iostream>
#include <bitset>
#include <cstring>
#include <cmath>

// Multiplication class
int Math::multiply(int x, int y) {
    // Define variables
    BinaryOp binaryOp;
    int sum = 0;
    int ShiftedX = x;
    std::string binary_y = binaryOp.get_binary(y);
    int len_y = binary_y.length();
    
    for (int i = len_y - 1; i >= 0; i--){
        if(binary_y[i] == '1'){
            sum = sum + ShiftedX;
        }
        ShiftedX = ShiftedX * 2;
    }

    return sum;
}

int Math::divide(int x, int y) {
    if (y > x) return 0;

    int q = divide(x, 2*y);

    if((x-2 * q * y) < y) {
        return 2 * q;
    }
    else {
        return 2* q + 1;
    }
}

int Math::sqrt(int x) {
    if (x < 0) return 0; 
    int y = 0;

    for (int j = 16 - 1; j >= 0; j--) {
        int temp = y + (1 << j);
        if (temp * temp <= x) {
            y = temp;
        }
    }

    return y;
}

int Math::min(int x, int y) {
    return (x < y) ? x : y;
}

int Math::max(int x, int y) {
    return (x > y) ? x : y;
}

int Math::abs(int x) {
    return (x < 0) ? -x : x;
}