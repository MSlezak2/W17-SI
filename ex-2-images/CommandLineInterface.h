#pragma once
#include "Image.h"
#include "ImageDataProviderInterface.h"

class CommandLineInterface {
public:
	CommandLineInterface() = default;
	~CommandLineInterface();
	int start(int argc, char* argv[]);

private:
	std::string inputImagePath1, inputImagePath2, outputImagePath, blendMode;
	int noThreads;
	std::string detemineFileExtension(std::string path);
};

