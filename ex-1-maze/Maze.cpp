#include "Maze.h"
#include <algorithm>

void Maze::putAt(char symbol, int x, int y) {
	if (0 < y && y < sizeof maze / sizeof maze[0]) {
		if (0 < x && x < sizeof maze / sizeof maze[0]) {
			maze[y][x] = symbol;
		}
	} 
}

char Maze::readAt(int x, int y) {
	// returns '?' if indexes are out of range
	char symbol{ '?' };

	if (0 < y && y < sizeof maze / sizeof maze[0]) {
		if (0 < x && x < sizeof maze / sizeof maze[0]) {
			symbol = maze[y][x];
		}
	}

	return symbol;
}

void Maze::serialize(FileIOInterface* io) {
	std::string line(' ',sizeof maze / sizeof maze[0]);
	for (int y = 0; y < sizeof maze ; y++) {
		for (int x = 0; x < sizeof maze / sizeof maze[0]; x++) {
			line[x] = maze[y][x];

		}
		io->write(line);
	}
}

void Maze::deserialize(FileIOInterface* io) {
	std::string line;
	for (int y = 0; y < sizeof maze; y++) {
		line = io->read();
		std::copy(line.begin(), line.end(), maze[y]);
	}
}
