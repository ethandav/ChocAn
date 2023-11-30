// Terminal.cpp
// Implementation file for the Terminal class, which handles all user input and display.

#include "Terminal.h"
#include "DataCenter.h"

/// <summary>
/// Creates a connection between the DataCenter and Terminal
/// </summary>
/// <param name="dc"> - Pointer to the initialized DataCenter</param>
void Terminal::connect(DataCenter* dc)
{
	this->dc = dc;
	if (this->dc == nullptr)
	{
		throw(std::runtime_error("Connection to Terminal failed."));
	}
}

/// <summary>
/// Starts terminal input loop and handles main menu user input
/// </summary>
void Terminal::open()
{
	int input = 0;
	running = true;

	while (running)
	{
		displayMenu();
		getIntInput(&input);
		switch (input)
		{
		case 1:
			dc->registerMember();
			break;
		case 2:
			dc->registerProvider();
			break;
		case 3:
			dc->updateMember();
			break;
		case 4:
			dc->updateProvider();
			break;
		case 5:
			dc->removeMember();
			break;
		case 6:
			dc->removeProvider();
			break;
		case 7:
			dc->getProviderDirectory();
			break;
		case 8:
			dc->enterServiceRecord();
			break;
		case 9:
			running = false;
			break;
		case 11: // created to populate to test reports, ignore
			dc->generateProviderReport();
		default:
			break;
		}
	}
}

/// <summary>
/// Shows Main Menu
/// </summary>
void Terminal::displayMenu()
{
	std::cout << "Welcome to ChocAn! Enter 9 to quit\n";
	std::cout << "1 - Register Member\n";
	std::cout << "2 - Register Provider\n";
	std::cout << "3 - Update Member\n";
	std::cout << "4 - Update Provider\n";
	std::cout << "5 - Remove Member\n";
	std::cout << "6 - Remove Provider\n";
	std::cout << "7 - Show Provider Directory\n";
	std::cout << "8 - Enter Service Record" << std::endl;
	std::cout << "Enter your choice: ";
}

/// <summary>
/// Prompts the user for a integer input. Validates input as int.
/// </summary>
/// <param name="input"> - Pointer to input variable</param>
void Terminal::getIntInput(int* input)
{
	while (true)
	{
		if (std::cin >> *input) {
			break;
		} else {
		    std::cout << "Invalid input. Please enter a valid integer: ";
			flushInput();
		}
	}
	flushInput();
}

/// <summary>
/// Prompts user for a char input. Validates input as char.
/// </summary>
/// <param name="input"> - Pointer to input variable</param>
void Terminal::getCharInput(char* input)
{
	while (true)
	{
		if (std::cin >> *input) {
			break;
		} else {
		    std::cout << "Invalid input. Please enter a valid character: ";
			flushInput();
		}
	}
	flushInput();
}

/// <summary>
/// Prompts the user for confirmation.
/// </summary>
/// <returns>True on user cofnimration. False if user selects N</returns>
bool Terminal::confirm()
{
	bool valid = false;
	while(!valid)
	{
		char confirm;
		while (true)
		{
			getCharInput(&confirm);
			switch (std::tolower(confirm))
			{
			case 'y':
				return true;
				break;
			case 'n':
				return false;
				break;
			default:
				displayString("Invalid input (y or n): ");
				break;
			}
		}

	}
}

/// <summary>
/// Populates a Person struct
/// </summary>
/// <param name="person"> - A Pointer to a Person Struct</param>
void Terminal::getPersonInput(Person* person)
{
	std::cout << "Name: ";
	std::cin >> person->name;
	flushInput();
	std::cout << "ID Number: ";
	getIntInput(&person->number);
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
	getIntInput(&person->address.zip);
}

/// <summary>
/// Populates a ServiceRecord struct
/// </summary>
/// <param name="record"> - A pointer to a ServiceRecord struct</param>
void Terminal::getServiceRecordInput(ServiceRecord* record)
{
	std::cout << "Date of Service (MM-DD-YYYY): ";
	std::getline(std::cin, record->servTime);
	std::cout << "Additional Comments: ";
	std::getline(std::cin, record->comments);
}

/// <summary>
/// Displays a string
/// </summary>
/// <param name="displayStr"> - A string from the DataCenter</param>
void Terminal::displayString(std::string displayStr)
{
	std::cout << displayStr;
}

/// <summary>
/// Flushes ci between multiple string inputs
/// </summary>
void Terminal::flushInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
