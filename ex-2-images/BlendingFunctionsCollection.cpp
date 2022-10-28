#include "BlendingFunctionsCollection.h"

BlendingFunctionsCollection::BlendingFunctionsCollection() {
	std::function<Image::color(Image::color, Image::color)> multiplyFcn = [](Image::color pixelA, Image::color pixelB) {
		Image::color c;
		c.r = pixelA.r * pixelB.r;
		c.g = pixelA.g * pixelB.g;
		c.b = pixelA.b * pixelB.b;
		return c;
	};
	addFunction("multiply", multiplyFcn);

	std::function<Image::color(Image::color, Image::color)> screenFcn = [](Image::color pixelA, Image::color pixelB) {
		Image::color c;
		c.r = 1 - (1 - pixelA.r) * (1 - pixelB.r);
		c.g = 1 - (1 - pixelA.g) * (1 - pixelB.g);
		c.b = 1 - (1 - pixelA.b) * (1 - pixelB.b);
		return c;
	};
	addFunction("screen", screenFcn);

	std::function<Image::color(Image::color, Image::color)> overlayFcn = [](Image::color pixelA, Image::color pixelB) {
		Image::color c;
		c.r = (pixelA.r < 0.5) ? (2 * pixelA.r * pixelB.r) : 1 - 2 * (1 - pixelA.r) * (1 - pixelB.r);
		c.g = (pixelA.g < 0.5) ? (2 * pixelA.g * pixelB.g) : 1 - 2 * (1 - pixelA.g) * (1 - pixelB.g);
		c.b = (pixelA.b < 0.5) ? (2 * pixelA.b * pixelB.b) : 1 - 2 * (1 - pixelA.b) * (1 - pixelB.b);
		return c;
	};
	addFunction("overlay", overlayFcn);

	std::function<Image::color(Image::color, Image::color)> differenceFcn = [](Image::color pixelA, Image::color pixelB) {
		Image::color c;
		c.r = abs(pixelA.r - pixelB.r);
		c.g = abs(pixelA.g - pixelB.g);
		c.b = abs(pixelA.b - pixelB.b);
		return c;
	};
	addFunction("difference", differenceFcn);
}

bool BlendingFunctionsCollection::addFunction(std::string functionName, std::function<Image::color(Image::color, Image::color)> actualFunction) {
	// returns false if insertion has failed
	std::pair<std::map<std::string, std::function<Image::color(Image::color, Image::color)>>::iterator, bool> result
		= blendingFunctionsCollection.insert({ functionName, actualFunction });
	return result.second;
}

std::function<Image::color(Image::color, Image::color)> BlendingFunctionsCollection::findFunction(std::string functionName) {
	// returns nullptr if there's no such function

	std::function<Image::color(Image::color, Image::color)> blendingFunction;
	std::map<std::string, std::function<Image::color(Image::color, Image::color)>>::iterator functionIterator =
		blendingFunctionsCollection.find(functionName);
	
	if (functionIterator != blendingFunctionsCollection.end()) {
		blendingFunction = functionIterator->second;
	} else {
		blendingFunction = nullptr;
	}

	return blendingFunction;
}
