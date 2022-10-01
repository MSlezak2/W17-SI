#pragma once
#include <string>

class FileIOInterface {
public:
	virtual ~FileIOInterface() = default;
	virtual std::string read() = 0;
	virtual bool write(std::string) = 0;
};

