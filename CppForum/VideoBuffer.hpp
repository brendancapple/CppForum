#pragma once

#include <iostream>
#include <string>

#define SCREEN_WIDTH 10
#define SCREEN_HEIGHT 5

class VideoBuffer {
private:
	uint32_t* buffer;

public: 
	VideoBuffer();
	~VideoBuffer();

	void render();
	void empty();

	void push(char content[]);
	void push(std::string content);
};