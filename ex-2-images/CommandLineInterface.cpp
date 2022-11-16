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

ImageProcessor::state CommandLineInterface::setup(int argc, char* argv[]) {

    try {
        boost::program_options::options_description desc("Allowed options"); //options declarations
        boost::program_options::variables_map vm; //variable for storing values of options
        
        //Declare options:
        defineOptions(desc);
        //Parse options and save them into variable
        parseOptions(argc, argv, desc, vm);
        //Determine which options has been used by user, and do appropriate actions
        handleOptions(vm, desc);

    } catch (std::exception& e) {
        std::cerr << "error: " << e.what() << "\n";
    }

    return settings;
}


void CommandLineInterface::parseOptions(int argc, char* argv[], boost::program_options::options_description& desc, boost::program_options::variables_map& vm) {
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
    boost::program_options::notify(vm);
}

void CommandLineInterface::defineOptions(boost::program_options::options_description& desc) {
    desc.add_options()
        ("help", "produce help message")
        ("input1,i1", boost::program_options::value<std::string>(), "path to the first of input images (including file extension)")
        ("input2,i2", boost::program_options::value<std::string>(), "path to the second of input images (including file extension)")
        ("output,o", boost::program_options::value<std::string>()->default_value("output_image.ppm"), "path to the output image (including file extension)")
        ("blend-mode,b", boost::program_options::value<std::string>(), "name of the blending filter function (multiply / screen / overlay / difference)")
        ("threads,t", boost::program_options::value<int>()->default_value(1), "number of threads for program to use")
        ;
}


void CommandLineInterface::handleOptions(boost::program_options::variables_map& vm, boost::program_options::options_description& desc) {
    if (vm.count("help") || vm.size() == 2) { // 2 because there are 2 default values
        std::cout << desc << "\n";
    }
    if (vm.count("input1")) {
        settings.input1_path = vm["input1"].as<std::string>();
    } else {
        throw std::invalid_argument("No input path (1) provided...");
    }
    if (vm.count("input2")) {
        settings.input2_path = vm["input2"].as<std::string>();
    } else {
        throw std::invalid_argument("No input path (2) provided...");
    }
    if (vm.count("output")) {
        settings.output_path = vm["output"].as<std::string>();
    } 
    if (vm.count("blend-mode")) {
        std::string blendMode = vm["blend-mode"].as<std::string>();
        BlendingFunctionsCollection blendingFunctionsCollection;
        settings.blend_function = blendingFunctionsCollection.findFunction(blendMode);
        if (settings.blend_function == nullptr) {
            throw std::invalid_argument("There no such blend mode");
        }
    } else {
        throw std::invalid_argument("No blend mode specified");
    }
    if (vm.count("threads")) {
        settings.num_threads = vm["threads"].as<int>();
    }
}

