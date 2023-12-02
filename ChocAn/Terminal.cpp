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
	isAdmin = false;

	displayLogin();

	if (isAdmin)
	{
		adminTerminal();

	}
	else
	{
		providerTerminal();
	}

}


//// <summary>
//// clears the screen for the menu to be redisplayed
//// </summary>
void Terminal::clearScreen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void Terminal::displayLogin()
{
	int choice = 0; 

	while (true)
	{
		std::cout << "Welcome to ChocAn\n";
		std::cout << "1 - ChocAn Manager Login\n";
		std::cout << "2 - Provider Login" << std::endl;
		std::cout << "9 - Quit" << std::endl;
		std::cout << "Enter your Choice: ";
		getIntInput(&choice);

		switch (choice)
		{
		case 1:
			isAdmin = true;
			return;
			break;
		case 2:
			return;
			break;
		case 9:
			running = false;
			exit(0);
			break;
		default:
			clearScreen();
			break;
		}
	}
}

void Terminal::adminTerminal()
{
	int input = 0;

	while (running)
	{
		displayAdminMenu();
		getIntInput(&input);
		clearScreen();
		switch (input)
		{
		case 1:
			dc->registerMember();
			waitForAny();
			break;
		case 2:
			dc->registerProvider();
			waitForAny();
			break;
		case 3:
			dc->updateMember();
			waitForAny();
			break;
		case 4:
			dc->updateProvider();
			waitForAny();
			break;
		case 5:
			dc->removeMember();
			waitForAny();
			break;
		case 6:
			dc->removeProvider();
			waitForAny();
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

void Terminal::providerTerminal()
{
	int input = 0;

	while (running)
	{
		displayProviderMenu();
		getIntInput(&input);
		switch (input)
		{
		case 1:
			dc->getProviderDirectory();
			waitForAny();
			break;
		case 2:
			dc->enterServiceRecord();
			waitForAny();
			break;
		case 9:
			running = false;
			break;
		default:
			break;
		}
	}
}

void Terminal::displayAdminMenu()
{
    clearScreen(); 

    std::cout << "\033[1;31m"; // Bold and red text
    std::cout << "+--------------------------------------+" << std::endl;
    std::cout << "|               ChocAn                 |" << std::endl;
    std::cout << "+--------------------------------------+" << std::endl;
    std::cout << "\033[0m"; 
    std::cout << "| Welcome to ChocAn! Enter 9 to quit   |" << std::endl;
    std::cout << "|--------------------------------------|" << std::endl;
    std::cout << "| 1 - Register Member                  |" << std::endl;
    std::cout << "| 2 - Register Provider                |" << std::endl;
    std::cout << "| 3 - Update Member                    |" << std::endl;
    std::cout << "| 4 - Update Provider                  |" << std::endl;
    std::cout << "| 5 - Remove Member                    |" << std::endl;
    std::cout << "| 6 - Remove Provider                  |" << std::endl;
    std::cout << "|--------------------------------------|" << std::endl;
    std::cout << "| Enter your choice: [ ]               |" << std::endl;
    std::cout << "\033[1;31m"; // Bold and red text
    std::cout << "+--------------------------------------+" << std::endl;
    std::cout << "|        © 2023 ChocAn Group 8         |" << std::endl;
    std::cout << "+--------------------------------------+" << std::endl;
    std::cout << "\033[0m"; 

    std::cout << "\033[A\033[A\033[A\033[A"; 
    std::cout << "\033[22C"; 
}

/// <summary>
/// Shows Main Menu
/// </summary>
void Terminal::displayProviderMenu()
{
    clearScreen(); 

    std::cout << "\033[1;31m"; // Bold and red text
    std::cout << "+--------------------------------------+" << std::endl;
    std::cout << "|               ChocAn                 |" << std::endl;
    std::cout << "+--------------------------------------+" << std::endl;
    std::cout << "\033[0m"; 
    std::cout << "| Welcome to ChocAn! Enter 9 to quit   |" << std::endl;
    std::cout << "|--------------------------------------|" << std::endl;
    std::cout << "| 1 - Show Provider Directory          |" << std::endl;
    std::cout << "| 2 - Enter Service Record             |" << std::endl;
    std::cout << "|--------------------------------------|" << std::endl;
    std::cout << "| Enter your choice: [ ]               |" << std::endl;
    std::cout << "\033[1;31m"; // Bold and red text
    std::cout << "+--------------------------------------+" << std::endl;
    std::cout << "|        © 2023 ChocAn Group 8         |" << std::endl;
    std::cout << "+--------------------------------------+" << std::endl;
    std::cout << "\033[0m"; 

    std::cout << "\033[A\033[A\033[A\033[A"; 
    std::cout << "\033[22C"; 
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
    // std::cout << displayStr;
    if (displayStr.find(',') != std::string::npos) {
        std::istringstream iss(displayStr);
        std::string line;
        std::cout << std::left << std::setw(10) << "ServiceCode" << std::setw(30) << "ServiceName" << std::setw(10) << "ServiceFee" << std::endl;
        std::cout << std::string(50, '-') << std::endl; 

        while (std::getline(iss, line)) {
            std::istringstream lineStream(line);
            std::string serviceCode, serviceName, serviceFee;
            getline(lineStream, serviceCode, ',');
            getline(lineStream, serviceName, ',');
            getline(lineStream, serviceFee);

            std::cout << std::left << std::setw(10) << serviceCode 
                      << std::setw(30) << serviceName 
                      << std::setw(10) << serviceFee << std::endl;
        }
    } else {
        std::cout << displayStr << std::endl;
    }
}

void Terminal::waitForAny()
{
    std::cout << "Press any key to return to the main menu...";
    std::cin.get(); 
}

/// <summary>
/// Flushes ci between multiple string inputs
/// </summary>
void Terminal::flushInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
