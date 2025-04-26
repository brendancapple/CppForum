#include "Animation.h"

Animation::Animation() {
	
}

Animation::Animation(char filepath[]) {
	this->load(filepath);
}

Animation::~Animation() {

}

void Animation::load(char filepath[]) {
	std::fstream file;
	file.open(filepath, std::ios::binary | std::ios::in);

	if (!file.is_open()) {
		throw std::invalid_argument("File not found!");
	}

	frames.clear();
	int frameCount;
	file.read((char*)&frameCount, sizeof(frameCount));

	for (int i = 0; i < frameCount; i++) {
		std::vector<Pixel> frame;
		int pixelCount;
		file.read((char*)&pixelCount, sizeof(pixelCount));

		for (int j = 0; j < pixelCount; j++) {
			Pixel pixel;
			file.read((char*)&pixel, sizeof(pixel));
			frame.push_back(pixel);
		}

		frames.push_back(frame);
	}
}

void Animation::save(char filepath[]) {
	std::ofstream file;
	file.open(filepath, std::ios::binary | std::ios::trunc | std::ios::out);

	if (!file.is_open()) {
		throw std::invalid_argument("Directory could not be opened!");
	}

	int frameCount = frames.size();
	file.write((char*)&frameCount, sizeof(frameCount));

	for (int i = 0; i < frameCount; i++) {
		int pixelCount = frames.at(i).size();
		file.write((char*)&pixelCount, sizeof(pixelCount));

		for (int j = 0; j < pixelCount; j++) {
			Pixel pixel = frames.at(i).at(j);
			file.write((char*)&pixel, sizeof(pixel));
		}
	}
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
