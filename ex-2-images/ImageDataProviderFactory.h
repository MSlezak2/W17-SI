#pragma once
#include <map>
#include <functional>
#include <string>
#include <memory>
#include "ImageDataProviderInterface.h"

class ImageDataProviderFactory {
public:
	ImageDataProviderFactory();
	//TODO: Is doing everything static is a good idea? 
	/*static*/ std::unique_ptr<ImageDataProviderInterface> createDataProvider(const std::string& ext);
	/*static*/ bool addNewFileExtension(std::string ext, std::function<std::unique_ptr<ImageDataProviderInterface>()> creator);

private:
	/*static*/ std::map<std::string, std::function<std::unique_ptr<ImageDataProviderInterface>()>> creators; //TODO: Came up with better name
};

