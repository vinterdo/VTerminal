#pragma once
#include <vector>
#include "Command.h"
#include <thread>
#include <queue>
#include <mutex>
#include <map>
#include "CommandRegistry.h"

class Command;

class CommandServer
{ 
public:
	CommandServer(); 
	virtual ~CommandServer();
	void runCommand(Command* command, std::vector<std::string> params);
	void runCommand(std::string command);
	void write(std::string);
	void outputCycle();
	void doInput(std::string input);
	void listThreads();
protected:
private:
	std::map<std::string, std::thread*> threads;
	std::mutex threadsMutex;
	std::queue<std::string> outputQueue;
	std::mutex outputMutex;
	std::thread cycleThread;
	void printOutput();
	int id = 0;
	static std::string getCurrentTime();
	void exec(std::string cmd);
	std::vector<std::string> split(std::string s, char splitter) const;
	CommandRegistry registry;
};
