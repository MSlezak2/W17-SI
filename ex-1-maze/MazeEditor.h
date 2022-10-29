#pragma once
#include "FileIOInterface.h"
#include "UserInterface.h"
#include "CommandManager.h"

class MazeEditor {
public:
	MazeEditor() : fileIO{ nullptr } {};
	MazeEditor(FileIOInterface* _fileIO) : fileIO{ _fileIO } {};
	void start();

private:
	CommandManager commandManager;
	FileIOInterface* fileIO;
	Maze maze;
	UserInterface ui;
};

