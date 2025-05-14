#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdexcept>

#include "VideoBuffer.hpp"
#include "Animation.h"
#include "Pixel.h"
#include "ImageConverter.h"

#include <opencv2/opencv.hpp>

// #include <windows.h>
// #pragma execution_character_set( "utf-8" )

int main(int argc, char* argv[]) {
    std::string filepath = "videos/depp.covid";
    if (argc > 1) {
        filepath = argv[1];
    }

    std::vector < std::string > filepaths = { "source_img/depp.jpg", "source_img/spider.jpg" };
    ImageConverter shauryasImageConverter(filepaths);
    std::vector<std::vector<Pixel>> frames = shauryasImageConverter.convert();

    Animation shauryasAnimation;
    for (std::vector<Pixel> v : frames) {
        shauryasAnimation.addFrame(v);
    }

    /*shauryasAnimation.save((char*) "videos/depp.covid");*/

    VideoBuffer shauryasVideoBuffer;
    shauryasVideoBuffer.empty();

    
    try {
        shauryasAnimation.load((char*) filepath.c_str());
    } 
    catch (std::invalid_argument e) {
        std::cerr << e.what() << "\n";
        std::cerr << filepath;
        std::exit(-1);
    }
    

    for (int i = 1; i < 20; i++) {
        shauryasVideoBuffer.empty();
        std::cout << "\x1b[2J\x1b[3J";
        shauryasVideoBuffer.push(shauryasAnimation.getFrame(i % shauryasAnimation.length()));
        // shauryasVideoBuffer.render();

        std::thread renderThread([&shauryasVideoBuffer] { shauryasVideoBuffer.render(); });

        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        renderThread.join();
    }

    std::cout << "\x1B[0m";
    return 0;
}