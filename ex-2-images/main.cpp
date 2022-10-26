#include <memory>
#include "ImageDataProviderInterface.h"
#include "ImageDataProviderFactory.h"
#include "ImageBlender.h"

int main() {

	ImageDataProviderFactory idpFactory;
	std::unique_ptr<ImageDataProviderInterface> imageDataProvider = idpFactory.createDataProvider(".png");

	Image img1(10, 10);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			img1(i, j).r = 1;
			img1(i, j).g = 0.5;
			img1(i, j).b = 0.5;
			img1(i, j).a = 1;
		}
	}
	Image img2(10, 10);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			img2(i, j).r = 0.5;
			img2(i, j).g = 1;
			img2(i, j).b = 0.5;
			img2(i, j).a = 1;
		}
	}

	ImageBlender imageBlender;

	std::function<Image::color(Image::color, Image::color)> blendFunction = [](Image::color a, Image::color b) {
		Image::color c;
		c.a = a.a * b.a;
		c.r = a.r * b.r;
		c.g = a.g * b.g;
		c.b = a.b * b.b;
		return c;
	};

	Image img3 = imageBlender.blendImages(img1, img2, 2, blendFunction);

	//imageDataProvider.get()->saveImage("the_test2.ppm",img);

	//Image img2 = imageDataProvider.get()->loadImage("the_test2.ppm");
	//imageDataProvider.get()->saveImage("the_test3.ppm", img2);

	//Image img2 = imageDataProvider.get()->loadImage("test_png_file_1.png");
	//imageDataProvider.get()->saveImage("test_png_file_2.png", img1);

	return 0;
}