// VTerminal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "Terminal.h"

using namespace std;

int main()
{
	Terminal* term = new Terminal();
	term->run();
	delete term;
	return 0;
}
