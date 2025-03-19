#include <string>
#include <iostream>

#include "VideoBuffer.hpp"

// #include <windows.h>
// #pragma execution_character_set( "utf-8" )

int main()
{
    // SetConsoleOutputCP(65001);

    VideoBuffer shauryasVideoBuffer;
    shauryasVideoBuffer.empty();

    std::string str = "abcdefghijklmnopqrstuvwxyz";
    shauryasVideoBuffer.push(str);

    shauryasVideoBuffer.render();

    std::cout << "\x1B[0m";
    return 0;
}