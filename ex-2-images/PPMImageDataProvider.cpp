#include "PPMImageDataProvider.h"
#include <bitset>
#include "WrongFileTypeException.h"
#include "IncorrectColorValueException.h"
#include "CorruptedFileException.h"

std::fstream PPMImageDataProvider::fileStream = std::fstream();

Image PPMImageDataProvider::loadImage(const std::string& path) const {
    Image img = Image(1, 1);

    fileStream.open(path, std::fstream::in);
    if (fileStream.is_open())
    {
        int width, height, maxColorValue;
        parseMetadata(width, height, maxColorValue);
        img = Image(width, height);
        parseAnActualImage(img, maxColorValue);
        fileStream.close();
    }

    return img;
}

void PPMImageDataProvider::parseMetadata(int& width, int& height, int& maxColorValue) const {
    std::string magicNumber;
    fileStream >> magicNumber;
    if (magicNumber != "P3") {
        throw WrongFileTypeException("PPM");
    }
    fileStream >> width;
    fileStream >> height;
    fileStream >> maxColorValue;
}

void PPMImageDataProvider::parseAnActualImage(Image& img, int maxColorValue) const {
    int r, g, b;
    for (int y = 0; y < img.getHeight(); y++) {
        for (int x = 0; x < img.getWidth(); x++) {
            fileStream >> r;
            img(y, x).r = mapTo0To1Range(r, maxColorValue);
            fileStream >> g;
            img(y, x).g = mapTo0To1Range(g, maxColorValue);
            fileStream >> b;
            img(y, x).b = mapTo0To1Range(b, maxColorValue);
            if (fileStream.fail()) {
                throw CorruptedFileException();
            }
        }
    }
}


bool PPMImageDataProvider::saveImage(const std::string& path, const Image& img) const {
    //returns false if operation of saving image fails
    bool success{ false };

    fileStream.open(path, std::fstream::out | std::fstream::trunc);
    if (fileStream.is_open()) {
        saveMetadata(img);
        saveAnActualImage(img);
        fileStream.close();
        success = true;
    }

    return success;
}

void PPMImageDataProvider::saveMetadata(const Image& img) const
{
    if (fileStream.is_open()) {
        fileStream << "P3" << "\n"; //magic number
        fileStream << img.getWidth() << "\n"; //image width
        fileStream << img.getHeight() << "\n"; //image height
        fileStream << MAX_COLOR_VALUE << "\n"; //maximum color value
    }
}

void PPMImageDataProvider::saveAnActualImage(const Image& img) const
{
    int r, g, b;
    for (int y = 0; y < img.getHeight(); y++) {
        for (int x = 0; x < img.getWidth(); x++) {
            fileStream << mapTo0ToMaxValueRange(img(x, y).r) << " ";
            fileStream << mapTo0ToMaxValueRange(img(x, y).g) << " ";
            fileStream << mapTo0ToMaxValueRange(img(x, y).b) << "  ";
        }
        fileStream << "\n";
    }
}

int PPMImageDataProvider::mapTo0ToMaxValueRange(float value) const {
    return floor(value * MAX_COLOR_VALUE);
}

float PPMImageDataProvider::mapTo0To1Range(int value, int maxColorValue) const {
    if (value < 0 || maxColorValue < value) {
        throw IncorrectColorValueException(maxColorValue);
    }
    return value / maxColorValue;
}

