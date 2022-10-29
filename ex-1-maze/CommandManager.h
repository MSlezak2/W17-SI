#pragma once
#include <map>
#include <functional>
#include <string>
#include <vector>

class CommandManager {
public:
	CommandManager();
	void invoke(std::string expression);
	void addCommand(std::string commandName, 
		std::function<bool(std::vector<std::string> action)>);


private:
	std::map<std::string,
		std::function<bool(std::vector<std::string>)>> commands;

	void invokeCommand(std::string& commandName, std::vector<std::string>& arguments);
	void parseExpression(std::string& expression, std::string& commandName, std::vector<std::string>& arguments);
};

