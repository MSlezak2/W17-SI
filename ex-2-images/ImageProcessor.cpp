#include "ImageProcessor.h"
#include "ImageBlender.h"
#include <sstream>

bool ImageProcessor::process() {
	bool success = true;

	if (areSettingsProvided()) {
		//Load input images:
		std::unique_ptr<Image> inputImage1 = loadImage(settings.input1_path);
		std::unique_ptr<Image> inputImage2 = loadImage(settings.input2_path);

		//Blend images:
		ImageBlender imageBlender;
		Image outputImage = imageBlender.blendImages(*inputImage1, *inputImage2, settings.num_threads, settings.blend_function);

		//Save resulting image:
		saveImage(settings.output_path, outputImage);
	} else {
		success = false;
	}

	return success;
}

std::unique_ptr<Image> ImageProcessor::loadImage(std::string path) {
	std::string extension = determineFileExtension(path);

	ImageDataProviderFactory imageDataProviderFactory;
	std::unique_ptr<ImageDataProviderInterface> imageDataProvider =
		imageDataProviderFactory.createDataProvider(extension);
	Image image = imageDataProvider.get()->loadImage(path);
	std::unique_ptr<Image> imagePtr(new Image(image));
	return imagePtr;
}

void ImageProcessor::saveImage(std::string path, const Image& image) {
	std::string extension = determineFileExtension(path);

	ImageDataProviderFactory imageDataProviderFactory;
	std::unique_ptr<ImageDataProviderInterface> imageDataProvider =
		imageDataProviderFactory.createDataProvider(extension);
	imageDataProvider.get()->saveImage(path, image);
}

std::string ImageProcessor::determineFileExtension(std::string path) {
	// returns the extension of the file
	std::string ext = "";

	std::stringstream ss(path);
	while (std::getline(ss, ext, '.')) {
	}

	return ext;
}

bool ImageProcessor::areSettingsProvided() {
	bool areProvided = true;

	if (settings.input1_path.size() == 0) {
		areProvided = false;
	} else if (settings.input2_path.size() == 0) {
		areProvided = false;
	} else if (settings.blend_function == nullptr) {
		areProvided = false;
	}

	return areProvided;
}
