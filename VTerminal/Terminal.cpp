#include "stdafx.h"
#include "Terminal.h"
#include <iostream>
#include <string>


Terminal::Terminal()
{
}

Terminal::~Terminal()
{
	//dtor
}

void Terminal::run()
{
	std::cout << std::endl << " >>> VTerminal v1.0 <<< " << std::endl << std::endl;
	bool done = false;

	while (!done)
	{
		std::cout << " > ";
		std::string input;
		std::cin >> input;
		server.doInput(input);
	}
}
