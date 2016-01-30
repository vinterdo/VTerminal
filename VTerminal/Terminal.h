#pragma once
#include <vector>
#include <string>
#include "CommandServer.h"

class Terminal
{
public:
	Terminal();
	virtual ~Terminal();
	void run();
	CommandServer server;
protected:
private:
};
