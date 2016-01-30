#include "stdafx.h"
#include "Command.h"
#include "CommandServer.h"
#include <iostream>

Command::Command()
{
}

Command::~Command()
{
}

void Command::run(CommandServer * server, std::vector<std::string> params)
{
}
