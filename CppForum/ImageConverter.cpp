#include "ImageConverter.h"

ImageConverter::ImageConverter() {

}

ImageConverter::ImageConverter(std::vector<std::string> filepaths) {
	filesToConvert = filepaths;
}

ImageConverter::~ImageConverter() {

}

void ImageConverter::push_image(std::string filepath) {
	filesToConvert.push_back(filepath);
}

std::vector<Pixel> ImageConverter::convert_single(int index) {
	cv::Mat working_img = cv::imread(filesToConvert.at(index), cv::IMREAD_COLOR);

    //std::cout << "img Loaded" << std::endl;

    float height_scale = SCREEN_HEIGHT / (float)working_img.rows;
    float width_scale = SCREEN_WIDTH / ( (float)working_img.cols * 2 );
    float scale_factor = height_scale < width_scale ? height_scale : width_scale;

    int height_target = working_img.rows * scale_factor;
    int width_target = working_img.cols * scale_factor;

    cv::Mat fit_img;
    cv::resize(working_img, fit_img, cv::Size(width_target * 2, height_target), cv::INTER_LINEAR);

    //std::cout << "img Scaled" << std::endl;

    std::vector<Pixel> frame;

    for (int i = 0; i < fit_img.rows; i++) {
        for (int j = 0; j < fit_img.cols; j++) {
            cv::Vec3b color_vec = fit_img.at<cv::Vec3b>(i, j);
            Pixel p = { i, j, color_vec[2], color_vec[1], color_vec[0], (char)219 };
            //std::cout << (int) i << "," << (int) j << " ";
            frame.push_back(p); 
        }
    }

    //std::cout << "img Framed of " << frame.size() << "px" << std::endl;
    return frame; 
}

std::vector<std::vector<Pixel>> ImageConverter::convert() {
    std::vector<std::vector<Pixel>> framer_of_the_constitution;
    
    for (int s = 0; s < filesToConvert.size(); s++) {
        framer_of_the_constitution.push_back( convert_single(s) );
    }

    //std::cout << "All Converted" << std::endl;
	return framer_of_the_constitution; 
}
