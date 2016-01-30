#pragma once
#include <string>
#include <vector>

class CommandServer;

class Command
{
public:
	Command();
	virtual ~Command();
	virtual void run(CommandServer * server, std::vector<std::string> params); 
protected:
private:
};
