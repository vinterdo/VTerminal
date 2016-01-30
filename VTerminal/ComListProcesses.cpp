#include "stdafx.h"
#include "ComListProcesses.h"
#include "CommandServer.h"


ComListProcesses::ComListProcesses()
{
}


ComListProcesses::~ComListProcesses()
{
}

void ComListProcesses::run(CommandServer * server, std::vector<std::string> params)
{
	server->listThreads();
}

