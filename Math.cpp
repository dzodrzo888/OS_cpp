#include "Math.h"
#include "BinaryOp.h"
#include <iostream>
#include <bitset>
#include <cstring>
#include <cmath>

// Multiplication class
int Math::multiply(int x, int y) {
    /*
    Multiplies two numbers
    */
    // Define variables
    BinaryOp binaryOp;
    int sum = 0;
    int ShiftedX = x;
    std::string binary_y = binaryOp.get_binary(y);
    int len_y = binary_y.length();
    
    // Loop over the X and add it to the sum if binary is 1
    for (int i = len_y - 1; i >= 0; i--){
        if(binary_y[i] == '1'){
            sum = sum + ShiftedX;
        }
        ShiftedX = ShiftedX * 2;
    }

    return sum;
}

int Math::divide(int x, int y) {
    /*
    Divides two numbers
    */
   // Return 0 if Y greater than X. Our divide does only ints.
    if (y > x) return 0;

    int q = divide(x, 2*y);

    // recursively look for the q
    if((x-2 * q * y) < y) {
        return 2 * q;
    }
    else {
        return 2* q + 1;
    }
}

int Math::sqrt(int x) {
    /*
    Square a number.
    */
    if (x < 0) return 0; 
    int y = 0;

    //Binary search for the desired num
    for (int j = 16 - 1; j >= 0; j--) {
        int temp = y + (1 << j);
        if (temp * temp <= x) {
            y = temp;
        }
    }

    return y;
}

int Math::min(int x, int y) {
    /*
    Choose the smaller number
    */
    return (x < y) ? x : y;
}

int Math::max(int x, int y) {
    /*
    Choose the larger number
    */
    return (x > y) ? x : y;
}

int Math::abs(int x) {
    /*
    Create a abs num
    */
    return (x < 0) ? -x : x;
}