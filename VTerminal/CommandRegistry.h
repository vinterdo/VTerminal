#pragma once

#include <map>
#include <string>
#include "Command.h"


class CommandRegistry
{
public:
	CommandRegistry();
	virtual ~CommandRegistry();
	Command* getCommand(std::string key);
	void add(std::string key, Command* command);
	bool contains(std::string key);
protected:
private:
	std::map<std::string, Command*> commands;
};