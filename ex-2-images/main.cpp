#include <memory>
#include "ImageDataProviderInterface.h"
#include "ImageDataProviderFactory.h"

int main() {

	ImageDataProviderFactory idpFactory;
	std::unique_ptr<ImageDataProviderInterface> imageDataProvider = idpFactory.createDataProvider(".ppm");

	Image img(10, 10);
	imageDataProvider.get()->saveImage("the_test1.ppm",img);

	return 0;
}