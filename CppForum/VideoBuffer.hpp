#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Pixel.h"

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 20

class VideoBuffer {
private:
	uint32_t* buffer;

public: 
	VideoBuffer();
	~VideoBuffer();

	void render();
	void empty();

	void push(char content[]);
	void push(char content[], uint8_t r, uint8_t g, uint8_t b);
	void push(std::string content);
	void push(std::string content, uint8_t r, uint8_t g, uint8_t b);
	void push(Pixel pixel);
	void push(std::vector<Pixel> pixels);
};