#pragma once
#include "Command.h"
class ComListProcesses :
	public Command
{
public:
	ComListProcesses();
	~ComListProcesses();
	void run(CommandServer* server, std::vector<std::string> params);
};

