#include "VideoBuffer.hpp"

VideoBuffer::VideoBuffer() {
	buffer = new uint32_t[SCREEN_WIDTH * SCREEN_HEIGHT];
}

VideoBuffer::~VideoBuffer() {
	delete[] buffer;
}

void VideoBuffer::render() {
    // 32 bits = 4 bytes 4 char Red-Green-Blue-Character
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            uint32_t p = (uint32_t) * (buffer + j + (i * SCREEN_WIDTH));
            std::cout << "\x1B[38;2;" << ((p >> 24) & 255) << ";" << ((p >> 16) & 255) << ";" << ((p >> 8) & 255) << "m" << (char)(p & 255);
        }
        std::cout << "\n";
    }
}

void VideoBuffer::empty() {
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
		*(buffer + i) = ' ';
}

void VideoBuffer::push(char content[]) {
    for (int i = 0; i < strlen(content); i++) {
        uint32_t tempPixel = (182 << 24) + (115 << 16) + (232 << 8);
        tempPixel += (char) content[i];
        *(buffer + i) = tempPixel;
    }
}

void VideoBuffer::push(std::string content) {
    for (int i = 0; i < content.length(); i++) {
        uint32_t tempPixel = (182 << 24) + (115 << 16) + (232 << 8);

        if (i >= sizeof(content)) {
            tempPixel += ' ';
            *(buffer + i) = tempPixel;
            continue;
        }
        tempPixel += (char)content[i];
        *(buffer + i) = tempPixel;
    }
}

