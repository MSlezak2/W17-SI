#pragma once
#include "ImageDataProviderInterface.h"

class PNGImageDataProvider :
    public ImageDataProviderInterface {
    // Inherited via ImageDataProviderInterface
    virtual Image loadImage(const std::string& path) const override;
    virtual void saveImage(const std::string& path, const Image& img) const override;
};
