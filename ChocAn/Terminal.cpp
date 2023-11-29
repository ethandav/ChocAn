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
		/* case 11: // created to populate to test reports, ignore
			dc->generateMemberReport();*/
		default:
			break;
		}
	}
}

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

void Terminal::getIntInput(int* input)
{
	std::cin >> *input;
	flushInput();
}

void Terminal::getCharInput(char* input)
{
	std::cin >> *input;
	flushInput();
}

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

void Terminal::getServiceRecordInput(ServiceRecord* record)
{
	std::cout << "Date of Service (MM-DD-YYYY): ";
	std::getline(std::cin, record->servTime);
	std::cout << "Additional Comments: ";
	std::getline(std::cin, record->comments);
}

void Terminal::displayString(std::string displayStr)
{
	std::cout << displayStr;
}

void Terminal::flushInput()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//void Terminal::updatePersonData(Registration& registration, Person* person) 
//{
//    if(!person) 
//	{
//        std::cout << "No person selected for update.\n";
//        return;
//    }
//
//    std::string name, addr, city, state;
//    int zip, number;
//
//    std::cout << "Enter new name: ";
//    std::getline(std::cin, name);
//    person->name = name;
//
//    std::cout << "Enter new address: ";
//    std::getline(std::cin, addr);
//    person->address.addr = addr;
//
//    std::cout << "Enter new city: ";
//    std::getline(std::cin, city);
//    person->address.city = city;
//
//    std::cout << "Enter new state: ";
//    std::getline(std::cin, state);
//    person->address.state = state;
//
//    std::cout << "Enter new zip code: ";
//    std::cin >> zip;
//    std::cin.ignore(); 
//    person->address.zip = zip;
//
//
//    std::cout << "Enter new number: ";
//    std::cin >> number;
//    std::cin.ignore(); 
//    person->number = number;
//
//    if (registration.editPerson(person)) {
//        std::cout << "Person data updated successfully.\n";
//    } else {
//        std::cout << "Failed to update person data.\n";
//    }
//}
