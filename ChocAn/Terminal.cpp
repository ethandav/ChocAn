#include "Terminal.h"
#include "Registration.h" // For Person struct

void Terminal::open()
{
	int input = 0;
	running = true;

	displayMenu();

	while (running)
	{
		getInputInt(&input);
		switch (input)
		{
		case 8:
			running = false;
			break;
		default:
			break;
		}
	}
}

void Terminal::displayMenu()
{
	std::cout << "Welcome to ChocAn! Enter 8 to quit" << std::endl;
}

void Terminal::getInputInt(int* input)
{
	std::cin >> *input;
}
