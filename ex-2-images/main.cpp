#include "CommandLineInterface.h"
#include "ImageProcessor.h"

int main(int argc, char* argv[]) {

	CommandLineInterface cli;
	ImageProcessor::state settings = cli.setup(argc, argv);

	ImageProcessor imageProcessor(settings);
	imageProcessor.process();

	return 0;
}
