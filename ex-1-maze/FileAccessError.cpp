#include "FileAccessError.h"

const char* FileAccessError::what() const noexcept {
    return errorMessage.c_str();
}
