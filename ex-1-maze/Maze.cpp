#include "Maze.h"

void Maze::putAt(char symbol, int x, int y) {
	if (0 < y && y < maze.size()) {
		if (0 < x && x < maze[0].size()) {
			maze[y][x] = symbol;
		}
	} 
}

char Maze::readAt(int x, int y) {
	// returns '?' if indexes are out of range
	char symbol{ '?' };

	if (0 < y && y < maze.size()) {
		if (0 < x && x < maze[0].size()) {
			symbol = maze[y][x];
		}
	}

	return symbol;
}

void Maze::serialize(std::string pathToFile) {
	
}

