#include "CommandManager.h"
#include <sstream>

CommandManager::CommandManager() {
}

void CommandManager::invoke(std::string expression) {
	std::string commandName;
	std::vector<std::string> arguments;
	
	parseExpression(expression, commandName, arguments);
	invokeCommand(commandName, arguments);
}

void CommandManager::parseExpression(std::string& expression, std::string& commandName, std::vector<std::string>& arguments) {
	std::stringstream ss(expression);
	std::string tempArgument;
	// parse command name
	ss >> commandName;
	// check if it exists
	if (commands.find(commandName) == commands.end()) {
		throw std::invalid_argument("There is no such command");
	}
	// parse arguments
	while (ss >> tempArgument) {
		arguments.push_back(tempArgument);
	}
}

void CommandManager::invokeCommand(std::string& commandName, std::vector<std::string>& arguments) {
	std::function<bool(std::vector<std::string>)> action;
	action = commands.find(commandName)->second;
	action(arguments);
}

void CommandManager::addCommand(
	std::string commandName, 
	std::function<bool(std::vector<std::string>)> action) {
	std::pair<
		std::string, 
		std::function<bool(std::vector<std::string>)>
	> pair = {commandName, action};

	commands.insert(pair);
}
