#include "PPMImageDataProvider.h"
#include <bitset>

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

    fileStream.open(path, std::fstream::out | std::fstream::trunc | std::fstream::binary);
    if (fileStream.is_open()) {
        // write metadata
        fileStream << "P6" << "\n"; //magic number
        fileStream << img.getWidth() << "\n"; //image width
        fileStream << img.getHeight() << "\n"; //image height
        fileStream << MAX_COLOR_VALUE << "\n"; //maximum color value
        //write the actual image
        char r, g, b;
        for (int y = 0; y < img.getHeight(); y++) {
            for (int x = 0; x < img.getWidth(); x++) {
                r = img(x, y).r;
                g = img(x, y).g;
                b = img(x, y).b;
                fileStream << r;//std::bitset<8>(r); // transform hexadecimal to binary (1-byte number)
                fileStream << g;//std::bitset<8>(g);
                fileStream << b;//std::bitset<8>(b);
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

