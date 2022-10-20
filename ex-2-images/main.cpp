#include <memory>
#include "ImageDataProviderInterface.h"
#include "ImageDataProviderFactory.h"

int main() {

	ImageDataProviderFactory idpFactory;
	std::unique_ptr<ImageDataProviderInterface> imageDataProvider = idpFactory.createDataProvider(".png");

	Image img1(10, 10);
	for (int i = 0; i < 10; i++) {
		img1(i, i).r = 0.4;
		img1(i, i).g = 0.4;
		img1(i, i).b = 0.4;
	}
	//imageDataProvider.get()->saveImage("the_test2.ppm",img);

	//Image img2 = imageDataProvider.get()->loadImage("the_test2.ppm");
	//imageDataProvider.get()->saveImage("the_test3.ppm", img2);

	Image img2 = imageDataProvider.get()->loadImage("test_png_file_1.png");
	imageDataProvider.get()->saveImage("test_png_file_2.png", img1);

	return 0;
}