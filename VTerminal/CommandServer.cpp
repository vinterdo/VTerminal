#include "stdafx.h"
#include "CommandServer.h"
#include <thread>
#include <iostream>
#include <sstream>
#include "ComRunPeriod.h"
#include "ComListProcesses.h"

CommandServer::CommandServer()
{
	registry.add("runPeriod", new ComRunPeriod());
	registry.add("listProc", new ComListProcesses());
	
	cycleThread = std::thread([&] {outputCycle(); });
}


CommandServer::~CommandServer()
{
}

void CommandServer::runCommand(Command* command, std::vector<std::string> params)
{
	std::lock_guard<std::mutex> guard(threadsMutex);
	std::string threadName = "" + id;
	id++;
	auto t1 = new std::thread([&](Command * command1) {command1->run(this, params); }, command);
	threads[threadName] = t1;
}

void CommandServer::runCommand(std::string command)
{
	std::lock_guard<std::mutex> guard(threadsMutex);
	std::string threadName = "" + id;
	id++;
	auto t1 = new std::thread([&](std::string command1) {exec(command1); }, command);
	threads[threadName] = t1;
}

void CommandServer::write(std::string msg)
{
	std::lock_guard<std::mutex> guard(outputMutex);
	outputQueue.push(msg);
}

void CommandServer::outputCycle()
{
	while (true)
	{
		printOutput();
	}
}

void CommandServer::printOutput()
{
	std::lock_guard<std::mutex> guard(outputMutex);
	while (outputQueue.size() != 0)
	{
		std::cout << "[" << getCurrentTime() + "] > " << outputQueue.front() << std::endl << " > ";
		outputQueue.pop(); 
	}
}

std::string CommandServer::getCurrentTime()
{
	auto time_point = std::chrono::system_clock::now();
	auto now_c = std::chrono::system_clock::to_time_t(time_point);
	char buffer[26];
	ctime_s(buffer, 26,&now_c);
	for (auto i = 0; i < 26; i++)
	{
		if (buffer[i] == '\n')
			buffer[i] = 0;
	}
	return buffer;
}

void CommandServer::exec(std::string cmd) {
	std::shared_ptr<FILE> pipe(_popen(cmd.c_str(), "r"), _pclose);
	if (!pipe) return;
	char buffer[2048];
	std::string result = "";
	while (!feof(pipe.get())) {
		if (fgets(buffer, 2048, pipe.get()) != nullptr)
			result += buffer;
	}
	write(result);
}


void CommandServer::doInput(std::string input)
{
	auto commands = split(input, ';');
	for (auto i = 0; i<commands.size(); i++)
	{
		auto params = split(commands[i], '-');
		if (params.size() > 0 && registry.contains(params[0]))
		{
			runCommand(registry.getCommand(params[0]), params);
		}
		else
		{
			runCommand(commands[i].c_str());
		}
	}
}


void CommandServer::listThreads()
{
	for(auto thread : threads)
	{
		auto myid = thread.second->get_id();
		std::stringstream ss;
		ss << myid;
		write(thread.first + " : " + ss.str());
	}
}

std::vector<std::string> CommandServer::split(std::string s, char splitter) const
{
	std::stringstream test(s);
	std::string                segment;
	std::vector<std::string>   seglist;

	while (std::getline(test, segment, splitter))
	{
		seglist.push_back(segment);
	}

	return seglist;
}
