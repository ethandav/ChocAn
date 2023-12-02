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

/// <summary>
/// Determines which Terminal view should be simulated
/// </summary>
void Terminal::displayLogin()
{
	int choice = 0; 

	while (true)
	{
	    std::cout << "\033[1;31m";
        std::cout << "+--------------------------------------+" << std::endl;
        std::cout << "|           Welcome to ChocAn          |" << std::endl;
        std::cout << "+--------------------------------------+" << std::endl;
        std::cout << "\033[0m";
        std::cout << "| 1 - ChocAn Manager Login             |" << std::endl;
        std::cout << "| 2 - Provider Login                   |" << std::endl;
        std::cout << "| 9 - Quit                             |" << std::endl;
		std::cout << "|--------------------------------------|" << std::endl;
		std::cout << "| Enter your choice: [ ]               |" << std::endl;
		std::cout << "\033[1;31m"; 
		std::cout << "+--------------------------------------+" << std::endl;
		std::cout << "|        © 2023 ChocAn Group 8         |" << std::endl;
		std::cout << "+--------------------------------------+" << std::endl;
		std::cout << "\033[0m"; 
		std::cout << "\033[A\033[A\033[A\033[A"; 
		std::cout << "\033[22C"; 
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

/// <summary>
/// Handles functionality for the Admin Terminal
/// </summary>
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
		case 7:
			dc->generateProviderReport();
			waitForAny();
			break;
		case 8:
			dc->generateMemberReport();
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

/// <summary>
/// Handles functionality for the Providers Terminal
/// </summary>
void Terminal::providerTerminal()
{
	int input = 0;

	while (running)
	{
		displayProviderMenu();
		getIntInput(&input);
		clearScreen();
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

    std::cout << "\033[1;31m";
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
    std::cout << "| 7 - Generate Provider Report         |" << std::endl;
    std::cout << "| 8 - Generate Member Report           |" << std::endl;
    std::cout << "|--------------------------------------|" << std::endl;
    std::cout << "| Enter your choice: [ ]               |" << std::endl;
    std::cout << "\033[1;31m"; 
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

    std::cout << "\033[1;31m";
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
    std::cout << "\033[1;31m";
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
	// Formatted entry limits 
	bool isValid = false;
	
	std::cout << "Name: ";
	std::getline(std::cin, person->name);
	person->name = person->name.substr(0, 25);
	std::cout << "ID Number: ";
	while (!isValid)
	{
		getIntInput(&person->number); 
		isValid = std::to_string(person->number).length() == 9;
		if (!isValid)
		{
			std::cout << "Invalid ID. Please enter a 9 digit number: ";
		}
	}
	std::cout << "Street Address: ";
	std::getline(std::cin, person->address.addr);
	person->address.addr = person->address.addr.substr(0, 25);
	std::cout << "City: ";
	std::getline(std::cin, person->address.city);
	person->address.city = person->address.city.substr(0, 14);
	std::cout << "State: ";
	std::getline(std::cin, person->address.state);
	person->address.state = person->address.state.substr(0, 2);
	isValid = false;
	std::cout << "Zip: ";
	while (!isValid) 
	{
		getIntInput(&person->address.zip); 
		isValid = std::to_string(person->address.zip).length() == 5;
		if (!isValid) 
		{
			std::cout << "Invalid zipcode. Please enter a 5 digit zipcode: ";
		}
	}
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
	record->comments = record->comments.substr(0, 100);
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
		std::cout << displayStr;
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
