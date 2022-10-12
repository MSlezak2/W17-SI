#pragma once
#include "Image.h"
#include <string>

class ImageDataProviderInterface { //TODO: Is it Creator or product? (I guess it's product)
public:
	virtual ~ImageDataProviderInterface() = default;
	virtual Image loadImage(const std::string& path) const = 0;
	virtual bool saveImage(const std::string& path, const Image& img) const = 0;
};

