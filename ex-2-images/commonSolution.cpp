//// ImageBlending.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//#include <functional>
//#include <thread>
//
//using namespace std;
//
//struct Color {
//    float r, g, b, a;
//    string printVal(float f) {
//        if (f > 0.75) return "#";
//        if (f > 0.5) return ";";
//        if (f > 0.25) return ".";
//        return " ";
//    }
//    string print() {
//        return printVal(r) + printVal(g) + printVal(b);
//    }
//};
//
//class Image {
//    vector<Color> data;
//    int width;
//    int height;
//    //void Load
//public:
//    Image(int _width = 0, int _height = 0) :width(_width), height(_height) {
//        data.resize(width * height);
//    }
//    Color& operator()(size_t x, size_t y) {
//        return data[x + y * width];
//        // 0,0 => 0
//        // x:0, y:1 => 0 + 1 * 20 => 20
//        // x:1, y:1 => 1 + 1 * 20 => 21
//    }
//    Color operator()(size_t x, size_t y) const {
//        return data[x + y * width];
//        // 0,0 => 0
//        // x:0, y:1 => 0 + 1 * 20 => 20
//        // x:1, y:1 => 1 + 1 * 20 => 21
//    }
//
//    void print() {
//        for (int y = 0; y < height; y++) {
//            for (int x = 0; x < width; x++) {
//                cout << this->operator()(x, y).print();
//            }
//            cout << endl;
//        }
//    }
//
//    int getWidth() const { return width; };
//    const int getHeight() const { return height; };
//};
//
//// interface
//class image_data_provider {
//public:
//    virtual Image load_image(const std::string& path) const = 0;
//    virtual void save_image(const std::string& path, const Image& img) const = 0;
//};
//
//class image_data_provider_factory : public image_data_provider {
//public:
//    Image load_image(const std::string& path) const override {
//        ifstream plik(path); // 
//        if (!plik) {
//            cout << "Brak pliku:" << path << endl;
//            return Image();
//        }
//        string tmp;
//        getline(plik, tmp); // P3
//        getline(plik, tmp); // # Created by GIMP version 2.10.32 PNM plug-in
//
//        int width, height;
//
//        plik >> width >> height;
//        Image obrazek(width, height);
//
//        int colorMaximum;
//        plik >> colorMaximum;
//
//
//        for (int y = 0; y < height; y++) {
//            for (int x = 0; x < width; x++) {
//                int red, green, blue;
//                plik >> red; // red => 255
//                obrazek(x, y).r = (float)red / colorMaximum;
//                plik >> green;
//                obrazek(x, y).g = (float)green / colorMaximum;
//                plik >> blue;
//                obrazek(x, y).b = (float)blue / colorMaximum;
//            }
//        }
//
//        return obrazek;
//    }
//    void save_image(const std::string& path, const Image& img) const override {
//        std::ofstream zap(path);
//        if (!zap.is_open()) {
//            std::cout << "Nie udalo sie" << std::endl;
//            return;
//        }
//        zap << "P3" << std::endl;
//        zap << img.getWidth() << " " << img.getHeight() << std::endl;
//        zap << 255 << std::endl;
//        for (int y = 0; y < img.getHeight(); y++) {
//            for (int x = 0; x < img.getWidth(); x++) {
//                zap << 255 * img(x, y).r << std::endl;
//                zap << 255 * img(x, y).g << std::endl;
//                zap << 255 * img(x, y).b << std::endl;
//            }
//        }
//    }
//};
//
//void blend_region(Image& output, const Image& imgA, const Image& imgB,
//    std::function<Color(Color,Color)> func, 
//    int minX, int minY, int maxX, int maxY) {
//    for (int y = minY; y < maxY; y++) {
//        for (int x = minX; x < maxX; x++) {
//            auto colorA = imgA(x, y);
//            auto colorB = imgB(x, y);
//            output(x, y) = func(colorA, colorB);
//        }
//    }
//}
//
//Color blendMultiply(Color a, Color b) {
//    Color res;
//    res.r = a.r * b.r;
//    res.g = a.g * b.g;
//    res.b = a.b * b.b;
//    return res;
//}
//
//Image blend_images(const Image& imgA, const Image& imgB, int numThreads,
//    std::function<Color(Color, Color)> func) {
//
//    int outWidth = imgA.getWidth();
//    int outHeight = imgA.getHeight();
//
//    //TODO: Znalezienie obszaru wynikowego
//
//    Image outImg(outWidth, outHeight);
//  
//    vector<std::thread> jobs;
//
//    for (int i = 0; i < numThreads; i++) {
//        jobs.push_back(std::thread(
//            blend_region,
//            std::ref(outImg),
//            std::ref(imgA),
//            std::ref(imgB),
//            func,
//            0, 0, outWidth, outHeight
//        ));
//    }
//
//    for (int i = 0; i < jobs.size(); i++) {
//        jobs[i].join();
//    }
//
//    return outImg;
//}
//
//Image openImage(const std::string& path) {
//
//    std::thread([]() {
//
//        });
//
//}
//
//int main() {
//    image_data_provider_factory fabryka;
//
//    Image wczytany1 = fabryka.load_image("C:\\Users\\nbvg67\\Downloads\\mona.ppm");
//    Image wczytany2 = fabryka.load_image("C:\\Users\\nbvg67\\Downloads\\mona.ppm");
//    
//    Image zblendowany = blend_images(wczytany2, wczytany1, 4, blendMultiply);
//
//    fabryka.save_image("test2.ppm", zblendowany);
//    //Image wczytany2 = fabryka.load_image("test.ppm");
//    //wczytany2.print();
//}