#include "UserInterface.h"
#include <iostream>

void UserInterface::displayMaze(Maze maze) {
	system("cls");
	for (int y = 0; y < maze.getHeight(); y++) {
		for (int x = 0; x < maze.getWidth(); x++) {
			std::cout << maze.readAt(x,y);
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

std::string UserInterface::askForCommand() {
	std::cout << "Enter command:\n";
	std::string command;
	std::getline(std::cin, command);
	return command;
}
