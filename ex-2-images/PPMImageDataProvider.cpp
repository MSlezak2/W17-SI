#include "PPMImageDataProvider.h"
#include <fstream>

Image PPMImageDataProvider::loadImage(const std::string& path) const {
    std::fstream fileStream;
    fileStream.open(path, std::fstream::in);
    // parse metadata



    // parse the actual image
    return Image(1,1);
}

void PPMImageDataProvider::saveImage(const std::string& path, const Image& img) const {}
