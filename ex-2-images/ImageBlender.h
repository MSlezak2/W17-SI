#pragma once
#include "Image.h"
#include <functional>

class ImageBlender {
public:
	Image blendImages(const Image& imageA, const Image& imageB, int noThreads, 
		std::function<Image::color(const Image::color, const Image::color)> blendFunction);

private:
	void blendRegion(Image& outputImage, const Image& imageA, const Image& imageB,
		std::function<Image::color(const Image::color, const Image::color)> blendFunction,
		int minX, int maxX, int minY, int maxY);
};

