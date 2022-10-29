#include "MazeEditor.h"

void MazeEditor::start() {
	std::string command;
	while (true) {
		ui.displayMaze(maze);
		command = ui.askForCommand();
		//commandManager.invoke(command);
	}
	
}
