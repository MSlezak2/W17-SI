#pragma once
#include "FileIOInterface.h"
#include "UserInterface.h"
#include "CommandManager.h"

class MazeEditor {
public:
	MazeEditor();
	void start();

private:
	CommandManager commandManager;
	Maze maze;
	UserInterface ui;

	void populateCommands();
};

