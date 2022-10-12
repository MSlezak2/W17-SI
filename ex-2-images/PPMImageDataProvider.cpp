#include "PPMImageDataProvider.h"
#include <fstream>

Image PPMImageDataProvider::loadImage(const std::string& path) const {
    //std::fstream fileStream;
    //fileStream.open(path, std::fstream::in);
    //// parse metadata



    //// parse the actual image
    return Image(1,1);
}

bool PPMImageDataProvider::saveImage(const std::string& path, const Image& img) const {
    //returns false if operation of saving image fails
    bool success{ false };

    std::fstream fileStream;
    fileStream.open(path, std::fstream::out | std::fstream::trunc);
    if (fileStream.is_open()) {
        // write metadata
        fileStream << "P6" << "\n"; //magic number
        fileStream << img.getWidth() << "\n"; //image width
        fileStream << img.getHeight() << "\n"; //image height
        fileStream << MAX_COLOR_VALUE << "\n"; //maximum color value
        //write the actual image
        int r, g, b;
        for (int y = 0; y < img.getHeight(); y++) {
            for (int x = 0; x < img.getWidth(); x++) {
                r = img(x, y).r;
                g = img(x, y).g;
                b = img(x, y).b;
                fileStream << r;
                fileStream << g; //TODO: transform hexadecimal to binary (1-byte number)
                fileStream << b;
                fileStream << " ";
            }
            fileStream << "\n";
        }

        fileStream.close();
        success = true;
    }

    return success;
}

int PPMImageDataProvider::mapTo0ToMaxValueRange(float value) {
    return floor(value * MAX_COLOR_VALUE);
}

