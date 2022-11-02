#include "CommandLineInterface.h"
#include "boost/program_options.hpp"
#include <iostream>
//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>

CommandLineInterface::CommandLineInterface(int argc2, char* argv2[]) {
	argc = argc2;
    // allocate memory and copy strings
    //argv = (char**)malloc((argc + 1) * sizeof * argv);
    //for (int i = 0; i < argc; ++i) {
    //    size_t length = strlen(argv[i]) + 1;
    //    argv[i] = (char*)malloc(length);
    //    memcpy(argv[i], argv[i], length);
    //}
    //argv[argc] = NULL;
    for (int i = 0; i < argc; i++) {
        argv[i] = argv2[i];
    }
    argv[argc] = nullptr;
}

CommandLineInterface::~CommandLineInterface() {
    //for (int i = 0; i < argc; ++i) {
    //    free(argv[i]);
    //}
    //free(argv);
}

int CommandLineInterface::start() {

    try {

        boost::program_options::options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce help message")
            ("compression", boost::program_options::value<double>(), "set compression level")
            ;

        boost::program_options::variables_map vm;
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        boost::program_options::notify(vm);

        if (vm.count("help")) {
            std::cout<< desc << "\n";
            return 0;
        }

        if (vm.count("compression")) {
            std::cout<< "Compression level was set to "
                << vm["compression"].as<double>() << ".\n";
        } else {
            std::cout<< "Compression level was not set.\n";
        }
    } catch (std::exception& e) {
        std::cerr << "error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
