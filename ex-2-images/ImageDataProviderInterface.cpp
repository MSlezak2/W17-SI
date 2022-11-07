#include "ImageDataProviderInterface.h"
#include "IncorrectColorValueException.h"

int ImageDataProviderInterface::mapTo0ToMaxValueRange(float value) const {
    return floor(value * Image::getMaxColorValue());
}

float ImageDataProviderInterface::mapTo0To1Range(int value, int maxColorValue) const {
    if (value < 0 || maxColorValue < value) {
        throw IncorrectColorValueException(maxColorValue);
    }
    return (double) value / maxColorValue;
}