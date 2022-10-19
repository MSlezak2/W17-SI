#include "IncorrectColorValueException.h"
#include "string"

IncorrectColorValueException::IncorrectColorValueException(int maxColorValue){
	exceptionMessage = "Value has either exceeded the max value (" + std::to_string(maxColorValue) + ") or is smaller than 0";
}

const char* IncorrectColorValueException::what() const noexcept
{
	return exceptionMessage.c_str();
}
