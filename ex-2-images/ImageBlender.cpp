#include "ImageBlender.h"
#include <algorithm>
#include <thread>

Image ImageBlender::blendImages(const Image& imageA, const Image& imageB, int noThreads, std::function<Image::color(const Image::color, const Image::color)> blendFunction) {
	// find region...
	Image outputImage = findImagesIntersection(imageA, imageB);

	// divide image...
	std::vector<std::thread> threads;
	int chunkSize = outputImage.getHeight() / noThreads;
	for (int i = 0; i < noThreads; i++) {

		std::thread th(&ImageBlender::blendRegion, this, std::ref(outputImage), std::ref(imageA), std::ref(imageB), blendFunction,
			0, outputImage.getWidth() - 1, i * chunkSize, (i + 1) * chunkSize - 1);
	
		threads.push_back(std::move(th));
	}
	// reminder:
	if (outputImage.getHeight() % noThreads != 0) {
		chunkSize = outputImage.getHeight() % noThreads;
		std::thread th(&ImageBlender::blendRegion, this, std::ref(outputImage), std::ref(imageA), std::ref(imageB), blendFunction,
			0, outputImage.getWidth() - 1, outputImage.getHeight() - chunkSize, outputImage.getHeight() - 1);

		threads.push_back(std::move(th));
	}

	for (int i = 0; i < threads.size(); i++) {
		threads[i].join();
	}
	
	return outputImage;
}

void ImageBlender::blendRegion(Image& outputImage, const Image& imageA, const Image& imageB, std::function<Image::color(const Image::color, const Image::color)> blendFunction, int minX, int maxX, int minY, int maxY) {
	//all boundaries are inclusive
	for (int y = minY; y <= maxY; y++) {
		for (int x = minX; x <= maxX; x++) {
			outputImage(x, y) = blendFunction(imageA(x,y), imageB(x,y));
		}
	}
}

Image ImageBlender::findImagesIntersection(const Image& imageA, const Image& imageB) {

	int outputWidth{ std::min(imageA.getWidth(), imageB.getWidth()) };
	int outputHeight{ std::min(imageA.getHeight(), imageB.getHeight()) };
	Image outputImage(outputWidth, outputHeight);

	return outputImage;
}


