#include "Sys.h"
#include <iostream>
#include <chrono>
#include <string>

Sys::Sys() : memory(1024), screen(), string(5) ,output(screen) {}

void Sys::halt() {
    while (true)
    {
        
    }
    
}

void Sys::wait(int duration) {
    auto start_time = std::chrono::steady_clock::now();

    while(true) {
        
        auto current_time = std::chrono::steady_clock::now();

        auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count();

        if(elapsed_time >= duration) {
            break;
        }
    }
}

void Sys::error(int error_code) {
    std::string str_err = string.int_to_str(error_code);
    output.print_string(str_err);
    std::cout << "Print string" << std::endl;
    screen.display_screen();
    std::cout << "We printed it on the screen" << std::endl;
}