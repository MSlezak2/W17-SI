#pragma once
#include <map>
#include <functional>
#include <string>
#include "Image.h"

class BlendingFunctionsCollection {
public:
	BlendingFunctionsCollection();
	/*static */bool addFunction(std::string functionName, 
		std::function<Image::color(Image::color, Image::color)> actualFunction);
	/*static */std::function<Image::color(Image::color, Image::color)> findFunction(std::string functionName);

private:
	/*static */std::map<std::string, std::function<Image::color(Image::color, Image::color)>> blendingFunctionsCollection;
};

