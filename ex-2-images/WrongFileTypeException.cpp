#include "WrongFileTypeException.h"

WrongFileTypeException::WrongFileTypeException(std::string expectedType)
{
    exceptionMessage = "Wrong file type. Expected type: " + expectedType;
}

const char* WrongFileTypeException::what() const noexcept
{
    return exceptionMessage.c_str();
}
