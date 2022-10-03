#pragma once
#include <array>
#include <string>
#include "FileIOInterface.h"

class Maze {
public:
	void putAt(char symbol, int x, int y);
	char readAt(int x, int y);
	void serialize(std::string pathToFile, FileIOInterface* io); //TODO: Where to put FileIOInterface??
	void deserialize(std::string pathToFile, FileIOInterface* io);

private:
	//TODO: How not to hardcode those values? const / macro / dynamic array / vactor?
	std::array<std::array<char, 10>, 5> maze;

};

