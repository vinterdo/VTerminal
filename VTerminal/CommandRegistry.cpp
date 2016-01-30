#include "stdafx.h"
#include "CommandRegistry.h"

CommandRegistry::CommandRegistry()
{
	//ctor
}

CommandRegistry::~CommandRegistry()
{
	//dtor
}
Command* CommandRegistry::getCommand(std::string key)
{
	return commands[key];
}

void CommandRegistry::add(std::string key, Command* command)
{
	commands[key] = command;
}

bool CommandRegistry::contains(std::string key)
{
	return commands.find(key) != commands.end();
}
