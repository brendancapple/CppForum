#include <iostream>
#include <string>

#include <windows.h>
#pragma execution_character_set( "utf-8" )

#define SCREEN_WIDTH 10
#define SCREEN_HEIGHT 5

void renderBuffer(char* buffer)
{
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            char c = (char)*(buffer + j + (i * SCREEN_WIDTH));
            std::cout << c;
        }
        std::cout << "\n";
    }
}

int main()
{
    char* videoBuffer = new char[SCREEN_WIDTH * SCREEN_HEIGHT];

    char str[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        if (str[i] == NULL) {
            *(videoBuffer + i) = ' ';
            continue;
        }
        *(videoBuffer + i) = str[i];
    }

    renderBuffer(videoBuffer);

    delete[] videoBuffer;
    return 0;
}