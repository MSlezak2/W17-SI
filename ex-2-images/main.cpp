#include <memory>
#include "ImageDataProviderInterface.h"
#include "ImageDataProviderFactory.h"

int main() {

	ImageDataProviderFactory idpFactory;
	std::unique_ptr<ImageDataProviderInterface> imageDataProvider = idpFactory.createDataProvider(".ppm");

	Image img(10, 10);
	for (int i = 0; i < 10; i++) {
		img(i, i).r = 1;
	}
	imageDataProvider.get()->saveImage("the_test2.ppm",img);

	Image img2 = imageDataProvider.get()->loadImage("the_test2.ppm");
	imageDataProvider.get()->saveImage("the_test3.ppm", img2);
	return 0;
}