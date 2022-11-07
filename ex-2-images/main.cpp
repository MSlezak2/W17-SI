#include <memory>
#include "ImageDataProviderInterface.h"
#include "ImageDataProviderFactory.h"
#include "ImageBlender.h"
#include "BlendingFunctionsCollection.h"
#include "CommandLineInterface.h"

int main(int argc, char* argv[]) {

	CommandLineInterface cli;
	cli.start(argc, argv);

	//ImageDataProviderFactory idpFactory;
	//std::unique_ptr<ImageDataProviderInterface> imageDataProvider = idpFactory.createDataProvider("ppm");

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

	//imageDataProvider.get()->saveImage("input1.ppm", img1);
	//imageDataProvider.get()->saveImage("input2.ppm", img2);
	//imageDataProvider.get()->saveImage("targetOutput.ppm",img3);

	return 0;
}