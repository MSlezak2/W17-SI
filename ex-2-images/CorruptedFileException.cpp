#include "CorruptedFileException.h"

CorruptedFileException::CorruptedFileException() {
	exceptionMessage = "Some data from the file is missing...";
}

const char* CorruptedFileException::what() const noexcept
{
	return exceptionMessage.c_str();
}
