#pragma once
#include "Command.h"
class ComRunPeriod :
	public Command
{
public:
	ComRunPeriod();
	~ComRunPeriod();
	void run(CommandServer * server, std::vector<std::string> params) override;
};

