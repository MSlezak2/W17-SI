#include "ImageDataProviderFactory.h"
#include "PPMImageDataProvider.h"
#include "PNGImageDataProvider.h"

ImageDataProviderFactory::ImageDataProviderFactory() {
	std::function<std::unique_ptr<ImageDataProviderInterface>()> ppmCreator = []() {
		return std::unique_ptr<ImageDataProviderInterface>{new PPMImageDataProvider()};
	};
	creators.insert({".ppm", ppmCreator});

	std::function<std::unique_ptr<ImageDataProviderInterface>()> pngCreator = []() {
		return std::unique_ptr<ImageDataProviderInterface>{new PNGImageDataProvider()};
	};
	creators.insert({ ".png", pngCreator });
}

std::unique_ptr<ImageDataProviderInterface> ImageDataProviderFactory::createDataProvider(const std::string& ext) {
	return creators.find(ext)->second();
}

bool ImageDataProviderFactory::addNewFileExtension(std::string ext, std::function<std::unique_ptr<ImageDataProviderInterface>()> creator) {
	// returns false if addition failed
	std::pair<std::map<std::string, std::function<std::unique_ptr<ImageDataProviderInterface>()>>::iterator, bool> result
		= creators.insert({"ext", creator});
	return result.second;
}
