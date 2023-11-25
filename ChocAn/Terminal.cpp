#include "Terminal.h"
#include "DataCenter.h"

void Terminal::connect(DataCenter* dc)
{
	this->dc = dc;
	if (this->dc == nullptr)
	{
		throw(std::runtime_error("Connection to Terminal failed."));
	}
}

void Terminal::open()
{
	int input = 0;
	running = true;

	while (running)
	{
		displayMenu();
		getInputInt(&input);
		switch (input)
		{
		case 1:
			dc->registerMember();
			break;
		case 2:
			dc->registerProvider();
			break;
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
	std::cout << "Welcome to ChocAn! Enter 8 to quit\n";
	std::cout << "1 - Register Member\n";
	std::cout << "2 - Register Provider\n";
}

void Terminal::getInputInt(int* input)
{
	std::cin >> *input;
}

void Terminal::getPersonInput(Person* person)
{
	std::cout << "Name: ";
	std::cin >> person->name;
	flushInput();
	std::cout << "ID Number: ";
	std::cin >> person->number;
	flushInput();
	std::cout << "Street Address: ";
	std::cin >> person->address.addr;
	flushInput();
	std::cout << "City: ";
	std::cin >> person->address.city;
	flushInput();
	std::cout << "State: ";
	std::cin >> person->address.state;
	flushInput();
	std::cout << "Zip: ";
	std::cin >> person->address.zip;
	flushInput();
}

void Terminal::displayString(std::string displayStr)
{
	std::cout << displayStr << std::endl;
}

void Terminal::flushInput()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
