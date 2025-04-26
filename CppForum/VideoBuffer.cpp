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
            std::cout << "\x1B[38;2;" << ((p >> 24) & 255) 
                << ";" << ((p >> 16) & 255) 
                << ";" << ((p >> 8) & 255) 
                << "m" << (char)(p & 255);
        }
        std::cout << "\n";
    }
}

void VideoBuffer::empty() {
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
		*(buffer + i) = ' ';
}

void VideoBuffer::push(char content[]) {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        if (i >= strlen(content))
            break;
        
        uint32_t tempPixel = (182 << 24) + (115 << 16) + (232 << 8);
        tempPixel += (char) content[i];
        *(buffer + i) = tempPixel;
    }
}

void VideoBuffer::push(char content[], uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        if (i >= strlen(content))
            break;

        uint32_t tempPixel = (r << 24) + (g << 16) + (b << 8);
        tempPixel += (char)content[i];
        *(buffer + i) = tempPixel;
    }
}

void VideoBuffer::push(std::string content) {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        if (i >= content.length())
            break;

        uint32_t tempPixel = (182 << 24) + (115 << 16) + (232 << 8);
        tempPixel += (char)content[i];
        *(buffer + i) = tempPixel;
    }
}

void VideoBuffer::push(std::string content, uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        if (i >= content.length())
            break;

        uint32_t tempPixel = (r << 24) + (g << 16) + (b << 8);
        tempPixel += (char)content[i];
        *(buffer + i) = tempPixel;
    }
}

void VideoBuffer::push(Pixel pixel) {
    uint32_t tempPixel = (pixel.r << 24) + (pixel.g << 16) + (pixel.b << 8);
    tempPixel += (char) pixel.c;
    *(buffer + pixel.row * SCREEN_WIDTH + pixel.col) = tempPixel;
}

void VideoBuffer::push(std::vector<Pixel> pixels) {
    for (Pixel p : pixels) {
        this->push(p);
    }
}

