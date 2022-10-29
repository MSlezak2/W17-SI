#pragma once
#include <array>
#include <string>
#include "FileIOInterface.h"

class Maze {
public:
	Maze();
	void putAt(char symbol, int x, int y);
	char readAt(int x, int y);
	void serialize(FileIOInterface* io); //TODO: Where to put FileIOInterface??
	void deserialize(FileIOInterface* io);
	int getHeight() { return HEIGHT; };
	int getWidth() { return WIDTH; };

private:
	//TODO: How not to hardcode those values? const / macro / dynamic array / vactor?
	static const int HEIGHT = 5;
	static const int WIDTH = 5;
	std::array<std::array<char, HEIGHT>, WIDTH> maze;
	//char maze[10][5];

};

