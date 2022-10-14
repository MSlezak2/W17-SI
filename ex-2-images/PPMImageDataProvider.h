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
    std::fstream fileStream;
    int mapTo0ToMaxValueRange(float value);
};

