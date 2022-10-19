#pragma once
#include <stdexcept>

class CorruptedFileException : public std::exception {
public:
	CorruptedFileException();

	virtual const char* what() const noexcept override;

private:
	std::string exceptionMessage;
};
