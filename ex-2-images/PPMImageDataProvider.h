#pragma once
#include "ImageDataProviderInterface.h"
#include <fstream>

class PPMImageDataProvider :
    public ImageDataProviderInterface {
public:
    // Inherited via ImageDataProviderInterface
    PPMImageDataProvider() = default;
    virtual Image loadImage(const std::string& path) const override;
    virtual bool saveImage(const std::string& path, const Image& img) const override;



private:
    const int MAX_COLOR_VALUE = 255;
    static std::fstream fileStream; // it's static because according to instruction, loadImage() has to be const

    int mapTo0ToMaxValueRange(float value) const;
    float mapTo0To1Range(int value, int maxColorValue) const;
    void parseMetadata(int& width, int& height, int& maxColorValue) const;
    void parseAnActualImage(Image& img, int maxColorValue) const;
    void saveMetadata(const Image& img) const;
    void saveAnActualImage(const Image& img) const;
};

