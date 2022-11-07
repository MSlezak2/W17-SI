#include "CommandLineInterface.h"
#include "boost/program_options.hpp"
#include <iostream>
#include "ImageDataProviderFactory.h"
#include "ImageBlender.h"
#include "BlendingFunctionsCollection.h"
//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>

//CommandLineInterface::CommandLineInterface(int argc2, char* argv2[]) {
//    /*ImageDataProviderFactory idpFactory;
//    imageDataProvider = idpFactory.createDataProvider(".png");*/
//    argc = argc2;
//    // allocate memory and copy strings
//    //argv = (char**)malloc((argc + 1) * sizeof * argv);
//    //for (int i = 0; i < argc; ++i) {
//    //    size_t length = strlen(argv[i]) + 1;
//    //    argv[i] = (char*)malloc(length);
//    //    memcpy(argv[i], argv[i], length);
//    //}
//    //argv[argc] = NULL;
//    //for (int i = 0; i < argc; i++) {
//        memcpy(argv, argv2, sizeof(argv2));
//        //argv[i] = _strdup(argv2[i]);
//    //}
//    argv[argc] = nullptr;
//}

CommandLineInterface::~CommandLineInterface() {
    //for (int i = 0; i < argc; ++i) {
    //    free(argv[i]);
    //}
    //free(argv);
}

int CommandLineInterface::start(int argc, char* argv[]) {

    try {

        boost::program_options::options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce help message")
            ("input1,i1", boost::program_options::value<std::string>(), "path to the first of input images")
            ("input2,i2", boost::program_options::value<std::string>(), "path to the second of input images")
            ("output,o", boost::program_options::value<std::string>(), "path to the output image")
            ("blend-mode,b", boost::program_options::value<std::string>(), "name of the blending filter function (multiply / screen / overlay / difference)")
            ("threads,t", boost::program_options::value<int>(), "number of threads for program to use")
            ;

        boost::program_options::variables_map vm;
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        boost::program_options::notify(vm);

        if (vm.count("help")) {
            std::cout<< desc << "\n";
        } else if (vm.count("input1")) {
            inputImagePath1 = vm["input1"].as<std::string>();
        } if (vm.count("input2")) {
            inputImagePath2 = vm["input2"].as<std::string>();
        } if (vm.count("output")) {
            outputImagePath = vm["output"].as<std::string>();
        } if (vm.count("blend-mode")) {
            blendMode = vm["blend-mode"].as<std::string>();
        } if (vm.count("threads")) {
            noThreads = vm["threads"].as<int>();
        } else {
            std::cout << desc << "\n";
        }
    } catch (std::exception& e) {
        std::cerr << "error: " << e.what() << "\n";
        return 1;
    }

    std::string inputImage1Extension = detemineFileExtension(inputImagePath1);
    std::string inputImage2Extension = detemineFileExtension(inputImagePath2);
    std::string outputImageExtension = detemineFileExtension(outputImagePath);

    ImageDataProviderFactory imageDataProviderFactory;
    std::unique_ptr<ImageDataProviderInterface> imageDataProvider = 
        imageDataProviderFactory.createDataProvider(inputImage1Extension);
    Image inputImage1 = imageDataProvider.get()->loadImage(inputImagePath1);
    imageDataProvider =
        imageDataProviderFactory.createDataProvider(inputImage2Extension);
    Image inputImage2 = imageDataProvider.get()->loadImage(inputImagePath2);

    ImageBlender imageBlender;

    BlendingFunctionsCollection blendingFunctionsCollection;
    std::function<Image::color(Image::color, Image::color)> blendFunction = blendingFunctionsCollection.findFunction(blendMode);
    Image outputImage = imageBlender.blendImages(inputImage1, inputImage2, noThreads, blendFunction);

    imageDataProvider =
        imageDataProviderFactory.createDataProvider(outputImageExtension);
    imageDataProvider.get()->saveImage(outputImagePath, outputImage);

    return 0;
}

std::string CommandLineInterface::detemineFileExtension(std::string path) {
    // returns the extension of the file
    std::string ext = "";
    
    std::stringstream ss(path);
    while (std::getline(ss,ext,'.')) {
    }

    return ext;
}
