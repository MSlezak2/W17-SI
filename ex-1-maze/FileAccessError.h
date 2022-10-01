#pragma once
#include <stdexcept>

class FileAccessError : public std::exception {
public:
	FileAccessError(std::string _errorMessage) : errorMessage{ _errorMessage } {};
	virtual const char* what() const noexcept override;

private:
	std::string errorMessage;
};

