#include <iostream>
#include <string>

#include <windows.h>
#pragma execution_character_set( "utf-8" )

#define SCREEN_WIDTH 10
#define SCREEN_HEIGHT 5

void renderBuffer(uint32_t* buffer)
{
    // 32 bits = 4 bytes 4 char Red-Green-Blue-Character
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            uint32_t p = (uint32_t) *(buffer + j + (i * SCREEN_WIDTH));
            std::cout << "\x1B[38;2;" << ((p >> 24) & 255) << ";" << ((p >> 16) & 255) << ";" << ((p >> 8) & 255) << "m" << (char) (p & 255);
        }
        std::cout << "\n";
    }
}

void clearBuffer(uint32_t* buffer) 
{
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
        *(buffer + i) = ' ';
}

int main()
{
    // SetConsoleOutputCP(65001);

    uint32_t* videoBuffer = new uint32_t[SCREEN_WIDTH * SCREEN_HEIGHT];
    clearBuffer(videoBuffer);

    char str[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        uint32_t tempPixel = (182 << 24) + (115 << 16) + (232 << 8);

        if (i >= sizeof(str)) {
            tempPixel += ' ';
            *(videoBuffer + i) = tempPixel;
            continue;
        }
        tempPixel += str[i];
        *(videoBuffer + i) = tempPixel;
    }

    renderBuffer(videoBuffer);

    delete[] videoBuffer;
    std::cout << "\x1B[0m";
    return 0;
}