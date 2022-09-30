#pragma once
#include "FileIOInterface.h"

class MazeEditor {
public:
	MazeEditor(FileIOInterface* _fileIO) : fileIO{ _fileIO } {};

private:
	FileIOInterface* fileIO;
};

