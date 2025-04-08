#include <string>
#include <iostream>
#include <chrono>
#include <thread>

#include "VideoBuffer.hpp"
#include "Animation.h"
#include "Pixel.h"

// #include <windows.h>
// #pragma execution_character_set( "utf-8" )

int main()
{
    // SetConsoleOutputCP(65001);

    VideoBuffer shauryasVideoBuffer;
    shauryasVideoBuffer.empty();

    char str[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    shauryasVideoBuffer.push(str);

    Pixel randomX = { 4, 8, 255, 0, 0, 'X' };
    Pixel randomEX = { 3, 8, 0, 0, 255, 'E' };
    Pixel randomL = { 2, 1, 255, 255, 0, 'L' };
    Pixel randomBL = { 2, 3, 0, 255, 255, 'B' };
    
    std::vector<Pixel> randomExes= { randomX, randomEX };
    std::vector<Pixel> randomEls = { randomL, randomBL };
    
    Animation shauryasAnimation;
    shauryasAnimation.addFrame(randomExes);
    shauryasAnimation.addFrame(randomEls);


    for (int i = 1; i < 20; i++) {
        shauryasVideoBuffer.empty();
        std::cout << "\x1b[2j";
        shauryasVideoBuffer.push(shauryasAnimation.getFrame(i % shauryasAnimation.length()));
        shauryasVideoBuffer.render();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "\x1B[0m";
    return 0;
}