#pragma once
#include "boost/program_options.hpp"
#include "Image.h"
#include "ImageDataProviderInterface.h"
#include <functional>

class CommandLineInterface {
public:
	CommandLineInterface() = default;
	~CommandLineInterface();
	int start(int argc, char* argv[]);


private:
	//std::string inputImagePath1, inputImagePath2, outputImagePath, blendMode;
	//int noThreads;
	std::string determineFileExtension(std::string path);
	void handleOptions(boost::program_options::variables_map& vm, boost::program_options::options_description& desc);
	void parseOptions(int argc, char* argv[], boost::program_options::options_description& desc, boost::program_options::variables_map& vm);
	void defineOptions(boost::program_options::options_description& desc);
	std::unique_ptr<Image> loadImage(std::string path);
	void saveImage(std::string path, const Image& image);

	struct state {
		std::string input1_path;
		std::string input2_path;
		std::string output_path;
		std::function<Image::color(Image::color, Image::color)> blend_function;
		size_t num_threads;
	};
	state settings;
};

