#include <string>
#include <iostream>

#include "VideoBuffer.hpp"
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
    
    std::vector<Pixel> randomExes= { randomX, randomEX };
    shauryasVideoBuffer.push(randomExes);

    shauryasVideoBuffer.render();

    std::cout << "\x1B[0m";
    return 0;
}