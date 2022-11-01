#include "Maze.h"
#include <algorithm>
#include <vector>

Maze::Maze() {
	// fill whole maze with wall tiles
	for (int i = 0; i < maze.size(); i++) {
		maze[i].fill('X');
	}
}

void Maze::putAt(char symbol, int x, int y) {
	if (0 <= y && y < maze.size()) {
		if (0 <= x && x < maze[0].size()) {
			maze[y][x] = symbol;
		}
	} 
}

char Maze::readAt(int x, int y) {
	// returns '?' if indexes are out of range
	char symbol{ '?' };

	if (0 <= y && y < maze.size()) {
		if (0 <= x && x < maze[0].size()) {
			symbol = maze[y][x];
		}
	}

	return symbol;
}

void Maze::serialize(FileIOInterface* io) {
	//TODO: This command probably should overwrite the file, but the instruction hinders it. 
	// That's why if user wants to save maze to the same file it doesn't work properly
	std::string line(maze[0].size(), ' ');
	for (int y = 0; y < maze.size(); y++) {
		for (int x = 0; x < maze[0].size(); x++) {
			line[x] = maze[y][x];
		}
		io->write(line);
	}
}

void Maze::deserialize(FileIOInterface* io) {
	std::string line;
	for (int y = 0; y < maze.size(); y++) {
		line = io->read();
		if (line.size() == WIDTH) {
			for (int x = 0; x < line.size(); x++) {
				maze[y][x] = line[x];
			}
		} else {
			throw std::exception("That file is corrupted");
		}
	}
}
