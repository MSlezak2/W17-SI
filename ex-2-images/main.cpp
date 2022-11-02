#include <memory>
#include "ImageDataProviderInterface.h"
#include "ImageDataProviderFactory.h"
#include "ImageBlender.h"
#include "BlendingFunctionsCollection.h"
#include "CommandLineInterface.h"

int main(int argc, char* argv[]) {

	CommandLineInterface cli(argc, argv);
	cli.start();

	//ImageDataProviderFactory idpFactory;
	//std::unique_ptr<ImageDataProviderInterface> imageDataProvider = idpFactory.createDataProvider(".png");

	//Image img1(10, 10);
	//for (int i = 0; i < 10; i++) {
	//	for (int j = 0; j < 10; j++) {
	//		img1(i, j).r = 1;
	//		img1(i, j).g = 0.5;
	//		img1(i, j).b = 0.5;
	//		img1(i, j).a = 1;
	//	}
	//}
	//Image img2(10, 10);
	//for (int i = 0; i < 10; i++) {
	//	for (int j = 0; j < 10; j++) {
	//		img2(i, j).r = 0.5;
	//		img2(i, j).g = 1;
	//		img2(i, j).b = 0.5;
	//		img2(i, j).a = 1;
	//	}
	//}

	//ImageBlender imageBlender;
	//BlendingFunctionsCollection blendingFunctionsCollection;
	//std::function<Image::color(Image::color, Image::color)> blendFunction = blendingFunctionsCollection.findFunction("overlay");
	//Image img3 = imageBlender.blendImages(img1, img2, 2, blendFunction);

	//imageDataProvider.get()->saveImage("the_test2.ppm",img);

	//Image img2 = imageDataProvider.get()->loadImage("the_test2.ppm");
	//imageDataProvider.get()->saveImage("the_test3.ppm", img2);

	//Image img2 = imageDataProvider.get()->loadImage("test_png_file_1.png");
	//imageDataProvider.get()->saveImage("test_png_file_2.png", img1);

		return 0;
}