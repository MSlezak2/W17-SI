#include "PNGImageDataProvider.h"
#define STB_IMAGE_IMPLEMENTATION
#include "external_libs/stb_image.h"
#define __STDC_LIB_EXT1__
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "external_libs/stb_image_write.h"

Image PNGImageDataProvider::loadImage(const std::string& path) const {

    int width, height, noComponentsPerPixel;
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &noComponentsPerPixel, 4); // noComponentsPerPixel - look at the documentation in stb_image.h

    Image image(width, height);
    int i = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {          
            image(x, y).r =  (int)data[i];
            image(x, y).g = (int)data[i+1];
            image(x, y).b = (int)data[i+2];
            image(x, y).a = (int)data[i+3];
            i+=4;
        }
    }

    stbi_image_free(data);

    return image;
}

bool PNGImageDataProvider::saveImage(const std::string& path, const Image& img) const {

    int noComponentsPerPixel = 4;
    char* imageData = new char[img.getHeight()*img.getWidth()*noComponentsPerPixel];

    int i = 0;
    for (int y = 0; y < img.getHeight(); y++) {
        for (int x = 0; x < img.getWidth(); x++) {
            imageData[i] = mapTo0ToMaxValueRange(img(x,y).r);
            imageData[i+1] = mapTo0ToMaxValueRange(img(x, y).g);
            imageData[i+2] = mapTo0ToMaxValueRange(img(x, y).b);
            imageData[i + 3] = mapTo0ToMaxValueRange(img(x, y).a);
            i += noComponentsPerPixel;
        }
    }

    int success = stbi_write_png(path.c_str(), img.getWidth(), img.getHeight(), noComponentsPerPixel, imageData, img.getWidth()*noComponentsPerPixel);

    delete[] imageData;

    return false;
}
