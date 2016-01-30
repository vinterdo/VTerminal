#include "stdafx.h"
#include "ComRunPeriod.h"
#include <thread>
#include "CommandServer.h"


ComRunPeriod::ComRunPeriod()
{
}


ComRunPeriod::~ComRunPeriod()
{
}

void ComRunPeriod::run(CommandServer * server, std::vector<std::string> params)
{
	while (true)
	{
		server->write("Running command " + params[1]);
		server->doInput(params[1]);
		std::this_thread::sleep_for(std::chrono::seconds(std::stoi(params[2])));
	}
}

