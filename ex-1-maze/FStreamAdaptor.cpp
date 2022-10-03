#include "FStreamAdaptor.h"
#include "FileAccessError.h"

FStreamAdaptor::FStreamAdaptor(std::string filePath) {
	currentPosition = 0;
	fileStream.open(filePath, std::ios::in | std::ios::app | std::ios::out);
	if (fileStream.fail()) {
		fileStream.clear();
		// TODO: Is that a good idea to throw an exception here?
		// TODO: Should I use one of existing exception classes instead of the custom one?
		throw FileAccessError("There was a problem with opening the file. Check the path.");
	}
}

FStreamAdaptor::~FStreamAdaptor() {
	fileStream.close();
}

std::string FStreamAdaptor::read() {
	// if end-of-file has been reached it returns an empty string

	std::string line{""};
	if (!fileStream.eof()) {
		std::getline(fileStream, line);
	}
	currentPosition = fileStream.tellg();

	return line;
}

bool FStreamAdaptor::write(std::string line) {
	bool success{ false };
	
	fileStream.seekp(0,std::fstream::end);
	fileStream << line << "\n";
	success = !fileStream.fail();
	fileStream.clear();
	fileStream.seekg(currentPosition); //for write operations not to disrupt read operations

	return success;
}
