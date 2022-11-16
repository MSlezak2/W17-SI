#include "ImageDataProviderFactory.h"
#include "PPMImageDataProvider.h"
#include "PNGImageDataProvider.h"

ImageDataProviderFactory::ImageDataProviderFactory() {
	std::function<std::unique_ptr<ImageDataProviderInterface>()> ppmCreator = []() {
		return std::unique_ptr<ImageDataProviderInterface>{new PPMImageDataProvider()};
	};
	addNewFileExtension("ppm", ppmCreator);

	std::function<std::unique_ptr<ImageDataProviderInterface>()> pngCreator = []() {
		return std::unique_ptr<ImageDataProviderInterface>{new PNGImageDataProvider()};
	};
	addNewFileExtension("png", pngCreator);
}

std::unique_ptr<ImageDataProviderInterface> ImageDataProviderFactory::createDataProvider(const std::string& ext) {
	std::unique_ptr<ImageDataProviderInterface> provider;
	std::map<std::string, std::function<std::unique_ptr<ImageDataProviderInterface>()>>::iterator providerItr = creators.find(ext);
	
	if (providerItr != creators.end()) {
		provider = providerItr->second();
	} else {
		provider = nullptr;
	}

	return provider;
}

bool ImageDataProviderFactory::addNewFileExtension(std::string ext, std::function<std::unique_ptr<ImageDataProviderInterface>()> creator) {
	// returns false if addition failed
	std::pair<std::map<std::string, std::function<std::unique_ptr<ImageDataProviderInterface>()>>::iterator, bool> result
		= creators.insert({ext, creator});
	return result.second;
}
