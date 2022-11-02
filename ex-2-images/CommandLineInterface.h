#pragma once

class CommandLineInterface {
public:
	CommandLineInterface(int argc2, char* argv2[]);
	~CommandLineInterface();
	int start();

private:
	int argc;
	//char** argv;
	char* argv[];
};

