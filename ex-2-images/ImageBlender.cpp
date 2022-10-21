#include "ImageBlender.h"
#include <algorithm>

Image ImageBlender::blendImages(const Image& imageA, const Image& imageB, int noThreads, std::function<Image::color(const Image::color, const Image::color)> blendFunction) {
	// find region...
	int outputWidth{ std::min(imageA.getWidth(), imageB.getWidth()) };
	int outputHeight{ std::min(imageA.getHeight(), imageB.getHeight()) };
	Image outputImage(outputWidth, outputHeight);

	// divide image...




}

void ImageBlender::blendRegion(Image& outputImage, const Image& imageA, const Image& imageB, std::function<Image::color(const Image::color, const Image::color)> blendFunction, int minX, int maxX, int minY, int maxY) {
	for (int y = minY; y <= maxY; y++) {
		for (int x = minX; x <= maxX; x++) {
			outputImage(x, y) = blendFunction(imageA(x,y), imageB(x,y));
		}
	}
}
