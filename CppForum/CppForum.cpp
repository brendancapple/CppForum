#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdexcept>

#include "VideoBuffer.hpp"
#include "Animation.h"
#include "Pixel.h"

// #include <windows.h>
// #pragma execution_character_set( "utf-8" )

int main(int argc, char* argv[]) {
    std::string filepath = "peanut butter";
    if (argc > 1) {
        filepath = argv[1];
    }


    VideoBuffer shauryasVideoBuffer;
    shauryasVideoBuffer.empty();

    Animation shauryasAnimation;
    try {
        shauryasAnimation.load((char*) filepath.c_str());
    } 
    catch (std::invalid_argument e) {
        std::cerr << e.what() << "\n";
        std::cerr << filepath;
        std::exit(-1);
    }

    for (int i = 1; i < 20; i++) {
        shauryasVideoBuffer.empty();
        std::cout << "\x1b[2J\x1b[3J";
        shauryasVideoBuffer.push(shauryasAnimation.getFrame(i % shauryasAnimation.length()));
        shauryasVideoBuffer.render();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "\x1B[0m";
    return 0;
}