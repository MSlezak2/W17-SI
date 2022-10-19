#pragma once
#include <stdexcept>

class IncorrectColorValueException : public std::exception {
public:
	IncorrectColorValueException(int maxColorValue);

	virtual const char* what() const noexcept override;

private:
	std::string exceptionMessage;
};
