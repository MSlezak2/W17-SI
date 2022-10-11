#include "PNGImageDataProvider.h"

Image PNGImageDataProvider::loadImage(const std::string& path) const {
    return Image(1,1);
}

void PNGImageDataProvider::saveImage(const std::string& path, const Image& img) const {}
