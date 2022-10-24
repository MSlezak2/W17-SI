#pragma once
#include "Image.h"
#include <string>

class ImageDataProviderInterface { //TODO: Is it Creator or product? (I guess it's a product)
public:
	virtual ~ImageDataProviderInterface() = default;
	virtual Image loadImage(const std::string& path) const = 0;
	virtual bool saveImage(const std::string& path, const Image& img) const = 0;

protected:
	//TODO: interface shouldn't contain any concrete members
	int mapTo0ToMaxValueRange(float value) const;
	float mapTo0To1Range(int value, int maxColorValue) const;
};

