#include "Image.h"
#include <stdexcept>

Image::Image(int _width, int _height) {
    width = _width;
    height = _height;
    pixels = std::vector<color>(width * height, color());
}

Image::color& Image::operator()(size_t x, size_t y) {
    //TODO: Is that the right way to return reference?
    if (0 > x || x > width || 0 > y || y > height) {
        throw std::out_of_range("Index out of range");
    }
    return pixels[y * width + x];
}

Image::color Image::operator()(size_t x, size_t y) const {
    if (0 > x || x > width || 0 > y || y > height) {
        throw std::out_of_range("Index out of range");
    }
    return pixels[y*width + x];
}

//Image::color Image::color::operator+(const color& rhs) {
//    Image::color c;
//    c.r = r + rhs.r;
//    c.g = g + rhs.g;
//    c.b = b + rhs.b;
//    return c;
//}
//
//Image::color Image::color::operator-(const color& rhs) {
//    Image::color c;
//    c.r = r - rhs.r;
//    c.g = g - rhs.g;
//    c.b = b - rhs.b;
//    return c;
//}
//
//Image::color Image::color::operator*(const color& rhs) {
//    Image::color c;
//    c.r = r * rhs.r;
//    c.g = g * rhs.g;
//    c.b = b * rhs.b;
//    return c;
//}
