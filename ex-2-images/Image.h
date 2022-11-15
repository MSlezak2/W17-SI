#pragma once
#include <vector>

class Image {
public:

	Image() = delete;
	Image(int _width, int _height);
	struct color {
		float r, g, b, a;
		color() : color(0,0,0,0) {};
		color(float r, float g, float b, float a) : r{ r }, g{ g }, b{ b }, a{ a } {};
	};
	color& operator()(size_t x, size_t y);
	color operator()(size_t x, size_t y) const;
	int getWidth() const { return width; };
	int getHeight() const { return height; };
	static int getMaxColorValue() { return MAX_COLOR_VALUE; };

private:
	int width, height;
	std::vector<color> pixels;
	static const int MAX_COLOR_VALUE = 255;

};

