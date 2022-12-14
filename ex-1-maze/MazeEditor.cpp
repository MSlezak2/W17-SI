#include "MazeEditor.h"
#include "FStreamAdaptor.h"
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>

MazeEditor::MazeEditor() {
	isOver = false;
	populateCommands();
}

void MazeEditor::start() {
	std::string command;
	while (!isOver) {
		ui.displayMaze(maze);
		command = ui.askForCommand();
		try {
			commandManager.invoke(command);
		} catch (const std::exception& e) {
			std::cout << e.what(); //TODO: Throwing exceptions is probably not the best / most efficient way to tackle that problem
			std::this_thread::sleep_for(std::chrono::seconds(3));
		}
	}
}

void MazeEditor::populateCommands() {
	// command used for editing the maze
	std::function<bool(std::vector<std::string>)> placeCommand = [this](std::vector<std::string> arguments) {
		//TODO: What if MazeEditor object no longer exists when this command is being executed? (Unlikely scenario but shouldn't I prevent it somehow?)
		bool succeeded{ true };
		// is there the right number of arguments
		if (arguments.size() != 3) {
			throw std::exception("Invalid number of arguments for this command");
		}
		// what type of tile to place
		std::string type = arguments[0];
		transform(type.begin(), type.end(), type.begin(), ::toupper);
		char c;
		if (type.compare("START") == 0) {
			c = 'S';
		} else if (type.compare("EXIT") == 0) {
			c = 'E';
		} else if (type.compare("WALL") == 0) {
			c = 'X';
		} else if (type.compare("SPACE") == 0) {
			c = ' ';
		} else {
			throw std::invalid_argument("There is no such type of the tile");
		}
		// where to place it
		int x = stoi(arguments[1]);
		int y = stoi(arguments[2]);
		if (x < 0 || x >= maze.getWidth() || y < 0 || y >= maze.getHeight()) {
			throw std::out_of_range("You've reached out of the scope");
		}
		// place the tile
		this->maze.putAt(c, x, y);
		return succeeded;
	};
	commandManager.addCommand("place", placeCommand);

	// command used for loading the maze from the file
	std::function<bool(std::vector<std::string>)> loadCommand = [this](std::vector<std::string> arguments) {
		bool succeeded{ true };
		// is there the right number of arguments
		if (arguments.size() != 1) {
			throw std::exception("Wrong number of arguments for this command");
		}
		// where to load the file from
		std::string filePath = arguments[0];
		FileIOInterface* fileIOInterface = new FStreamAdaptor(filePath);
		// load the file
		this->maze.deserialize(fileIOInterface);
		delete fileIOInterface;
		return succeeded;
	};
	commandManager.addCommand("load", loadCommand);

	// command used for saving the maze to the file
	std::function<bool(std::vector<std::string>)> saveCommand = [this](std::vector<std::string> arguments) {
		bool succeeded{ true };
		// is there the right number of arguments
		if (arguments.size() != 1) {
			throw std::exception("Wrong number of arguments for this command");
		}
		// where to save the maze
		std::string filePath = arguments[0];
		FileIOInterface* fileIOInterface = new FStreamAdaptor(filePath);
		// save the maze
		this->maze.serialize(fileIOInterface);
		delete fileIOInterface;
		return succeeded;
	};
	commandManager.addCommand("save", saveCommand);

	// command to exit the program
	std::function<bool(std::vector<std::string>)> exitCommand = [this](std::vector<std::string> arguments) {
		bool succeeded{ true };
		this->isOver = true;
		return succeeded;
	};
	commandManager.addCommand("exit", exitCommand);
}