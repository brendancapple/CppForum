#include "Animation.h"

Animation::Animation() {
	
}

Animation::Animation(char filepath[]) {
	this->load(filepath);
}

Animation::~Animation() {

}

void Animation::load(char filepath[]) {
	
}

void Animation::save(char filepath[]) {

}

int Animation::length() {
	return frames.size();
}

std::vector<Pixel> Animation::getFrame(int index) {
	return frames.at(index);
}

void Animation::addFrame(std::vector<Pixel> pixels) {
	frames.push_back(pixels);
}
