#ifndef SYS_H
#define SYS_H
#include "Memory.h"
#include "Screen.h"
#include "Output.h"
#include "String.h"

class Sys {
public:
    Sys();

    void halt();
    void wait(int duration);
    void error(int error_code);

    Screen screen;
    Output output;
    Memory memory;
    String string;
private:

};


#endif