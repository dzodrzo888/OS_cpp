#ifndef OUTPUT_H
#define OUTPUT_H
#include <iostream>
#include <vector>

class Output {

public:
    Output();

    void create(int index, int a, int b, int c, int d, int e,
		         int f, int g, int h, int i, int j, int k);
    
private:
    std::vector<std::vector<int>> char_maps;
};


#endif