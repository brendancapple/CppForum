#pragma once

#include <vector>
#include <fstream>
#include <stdexcept>

#include "Pixel.h"

class Animation {
private:
	std::vector<std::vector<Pixel>> frames;

public:
	Animation();
	Animation(char filepath[]);
	~Animation();

	void load(char filepath[]);
	void save(char filepath[]);
	int length();

	std::vector<Pixel> getFrame(int index);
	void addFrame(std::vector<Pixel> pixels);
};