#pragma once
#include <string>
#include <memory>
#include "Image.h"
#include "ImageDataProviderFactory.h"

class ImageProcessor {
public:
	struct state {
		std::string input1_path;
		std::string input2_path;
		std::string output_path;
		std::function<Image::color(Image::color, Image::color)> blend_function;
		size_t num_threads;
	};
	ImageProcessor(state settings) : settings{ settings } {};
	bool process();

private:
	state settings;
	std::unique_ptr<Image> loadImage(std::string path);
	void saveImage(std::string path, const Image& image);
	std::string determineFileExtension(std::string path);
	bool areSettingsProvided();
};

