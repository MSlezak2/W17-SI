#pragma once
#include <vector>

class Image {
public:

	Image() = delete;
	Image(int width, int height) : width{ width }, height{ height } {};
	struct color {
		float r, g, b, a;
	};
	color& operator()(size_t x, size_t y);
	color operator()(size_t x, size_t y) const;

private:
	int width, height;
	std::vector<color> pixels;

};

