#include "FStreamAdaptor.h"
#include <iostream>
#include "CommandManager.h"
#include "Maze.h"
#include "MazeEditor.h"

int main() {

	//FStreamAdaptor fStreamAdaptor("test.txt");
	////std::cout << fStreamAdaptor.read();
	//std::string test1 = fStreamAdaptor.read();
	//std::string test2 = fStreamAdaptor.read();
	//bool test5 = fStreamAdaptor.write("ABCD4");
	//std::string test3 = fStreamAdaptor.read();
	//std::string test4 = fStreamAdaptor.read();

	CommandManager commandManager;
	std::function<bool(std::vector<std::string>)> newCommand = [](std::vector<std::string> arguments) {
		bool succeeded{ false };
		if (arguments.size() > 0) {
			succeeded = true;
		}
		return succeeded;
	};
	commandManager.addCommand("testCommand", newCommand);

	commandManager.invoke("testCommand asdf asdf");

	MazeEditor mazeEditor;
	mazeEditor.start();



	return 0;
}