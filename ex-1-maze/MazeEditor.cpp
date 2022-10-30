#include "MazeEditor.h"
#include "FStreamAdaptor.h"

MazeEditor::MazeEditor() {
	populateCommands();
}

void MazeEditor::start() {
	std::string command;
	while (true) {
		ui.displayMaze(maze);
		command = ui.askForCommand();
		commandManager.invoke(command);
	}
}

void MazeEditor::populateCommands() {
	std::function<bool(std::vector<std::string>)> placeCommand = [this](std::vector<std::string> arguments) {
		bool succeeded{ true };
		//TODO: Handle invalid usage
		char type = arguments[0][0];
		int x = stoi(arguments[1]);
		int y = stoi(arguments[2]);
		this->maze.putAt(type, x, y);
		return succeeded;
	};
	commandManager.addCommand("place", placeCommand);

	std::function<bool(std::vector<std::string>)> loadCommand = [this](std::vector<std::string> arguments) {
		bool succeeded{ true };
		//TODO: Handle invalid usage
		std::string filePath = arguments[0];
		FileIOInterface* fileIOInterface = new FStreamAdaptor(filePath);
		this->maze.deserialize(fileIOInterface);
		delete fileIOInterface;
		return succeeded;
	};
	commandManager.addCommand("load", loadCommand);

	std::function<bool(std::vector<std::string>)> saveCommand = [this](std::vector<std::string> arguments) {
		bool succeeded{ true };
		//TODO: Handle invalid usage
		std::string filePath = arguments[0];
		FileIOInterface* fileIOInterface = new FStreamAdaptor(filePath);
		this->maze.serialize(fileIOInterface);
		delete fileIOInterface;
		return succeeded;
	};
	commandManager.addCommand("save", saveCommand);
}