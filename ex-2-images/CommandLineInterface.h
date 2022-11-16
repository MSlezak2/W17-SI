#pragma once
#include "boost/program_options.hpp"
#include "Image.h"
#include "ImageDataProviderInterface.h"
#include <functional>
#include "ImageProcessor.h"

class CommandLineInterface {
public:
	CommandLineInterface() = default;
	~CommandLineInterface();
	ImageProcessor::state setup(int argc, char* argv[]);


private:
	std::string determineFileExtension(std::string path);
	void handleOptions(boost::program_options::variables_map& vm, boost::program_options::options_description& desc);
	void parseOptions(int argc, char* argv[], boost::program_options::options_description& desc, boost::program_options::variables_map& vm);
	void defineOptions(boost::program_options::options_description& desc);
	std::unique_ptr<Image> loadImage(std::string path);
	void saveImage(std::string path, const Image& image);

	ImageProcessor::state settings;
};

