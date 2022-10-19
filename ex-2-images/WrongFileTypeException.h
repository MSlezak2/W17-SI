#pragma once
#include <stdexcept>

class WrongFileTypeException : public std::exception {
public:
	WrongFileTypeException(std::string expectedType);

	virtual const char* what() const noexcept override;

private:
	std::string exceptionMessage;
};
