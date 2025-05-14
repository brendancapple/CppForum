#pragma once

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <string>
#include <vector>

#include "Pixel.h"
#include "VideoBuffer.hpp"

class ImageConverter {
private:
	std::vector<std::string> filesToConvert;
	// cv::Mat workingImg;

public:
	ImageConverter();
	ImageConverter(std::vector<std::string> filepaths);
	~ImageConverter();

	void push_image(std::string filepath);
	std::vector<Pixel> convert_single(int index);
	std::vector<std::vector<Pixel>> convert();
};