// DataCenter.cpp
// This is the implementation file for the DataCenter class. The DataCenter is the primary driver
// of the ChocAn system and is responsible for the interactions between components.
// The DataCenter breaks the components up into abstractions and serves as the interface for
// all functionality of the system.

#include "DataCenter.h"

/// <summary>
/// Initializes the DataCenter and opens a connection with the Terminal
/// </summary>
void DataCenter::start()
{
	try
	{
		terminal.connect(this);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	terminal.open();
}

/// <summary>
/// Register a new member. Creates a new Person object and passes the pointer to
/// the Terminal to gather input.
/// </summary>
void DataCenter::registerMember()
{
	Person* newMember = new Person();
	terminal.getPersonInput(newMember);

	if (registration.registerMember(newMember))
	{
		terminal.displayString("Member succesfully Added!\n");
	}
}

/// <summary>
/// Register a new Provider. Creates a new Person object and passes the pointer to
/// the Terminal to gather input.
/// </summary>
void DataCenter::registerProvider()
{
	Person* newProvider = new Person();
	terminal.getPersonInput(newProvider);

	if (registration.registerProvider(newProvider))
	{
		terminal.displayString("Provider succesfully Added!\n");
	}
}

/// <summary>
/// Update an existing Member. The user is prompted for a member number. On validation of
/// the member number, a pointer to the member is retrieved from the Registration class.
/// </summary>
void DataCenter::updateMember()
{
	int		memberNumber	= 0;
	Person* person			= nullptr;

	terminal.displayString("Member Number: ");
	terminal.getIntInput(&memberNumber);

	// Retrieve existing Person struct from member list
	person = registration.getMember(memberNumber);
	if (person == nullptr)
	{
		terminal.displayString("Member not found\n");
		return;
	}

	// Call the function to edit the Person Struct
	editPerson(person);
}

/// <summary>
/// Update an existing Provider. The user is prompted for a provider number. On validation of
/// the provider number, a pointer to the provider is retrieved from the Registration class.
/// </summary>
void DataCenter::updateProvider()
{
	int		providerNumber	= 0;
	Person* person			= nullptr;

	terminal.displayString("Provider Number: ");
	terminal.getIntInput(&providerNumber);

	person = registration.getProvider(providerNumber);
	if (person == nullptr)
	{
		terminal.displayString("Provider not found\n");
		return;
	}

	editPerson(person);
}

/// <summary>
/// Delete a member from the system. Prompts the user for a member number and on validation,
/// calls the registration class to delete the member from the list.
/// </summary>
void DataCenter::removeMember()
{
	int memberNumber = 0;

	terminal.displayString("Member Number: ");
	terminal.getIntInput(&memberNumber);
	if (registration.removeMember(memberNumber))
	{
		terminal.displayString("Member Removed\n");
	}
	else
	{
		terminal.displayString("Member not found\n");
	}
}

/// <summary>
/// Delete a provider from the system. Prompts the user for a provider number and on validation,
/// calls the registration class to delete the provider from the list.
/// </summary>
void DataCenter::removeProvider()
{
	int providerNumber = 0;
	terminal.displayString("Provider Number: ");
	terminal.getIntInput(&providerNumber);
	if (registration.removeProvider(providerNumber))
	{
		terminal.displayString("Provider Removed\n");
	}
	else
	{
		terminal.displayString("Provider not found\n");
	}
}

/// <summary>
/// Prompts the user for a member number via the Terminal and validates it via the registration class
/// </summary>
void DataCenter::validateMember()
{
	int memberNumber = 0;
	terminal.displayString("Member Number: ");
	terminal.getIntInput(&memberNumber);
	if (registration.validateMemberCard(memberNumber))
	{
		terminal.displayString("MemberCard Valid\n");
	}
	else
	{
		terminal.displayString("MemberCard Invalid\n");
	}
}

//Reports
void DataCenter::generateMemberReport()
{
	// need registration and filesystem to get info when writing service record (provider name and service name)
	const std::list<Person*>& members = registration.getMemberList();
	if(reports.generateMemberReports(members, registration, filesystem))
	{
		terminal.displayString("Member Report Generation Success\n");
	}
	else
	{
		terminal.displayString("Member Report Generation Failed\n");
	}
	
}

void DataCenter::generateProviderReport()
{
	const std::list<Person*>& providers = registration.getProviderList();
	if(reports.generateProviderReports(providers, registration, filesystem))
	{
		terminal.displayString("Provider Report Generation Success\n");
	}
	else
	{
		terminal.displayString("Provider Report Generation Failed\n");
	}
}

void DataCenter::generateSummaryReport()
{

}

/// <summary>
/// Retrieves the provider directory from the Filesystem class and displays to the terminal
/// </summary>
void DataCenter::getProviderDirectory()
{
	terminal.displayString(filesystem.getProviderDirectory());
}

/// <summary>
/// Allows a provider to create a new service record for a member. First validates both member and provider
/// numbers, then gathers serviceRecord struct info via the terminal. Then the provider is prompted for the service
/// code, which is validated via the terminal.
/// </summary>
void DataCenter::enterServiceRecord()
{
	ServiceRecord*		record			= nullptr;
	Person*				provider		= nullptr;
	Person*				member			= nullptr;
	auto				now				= std::chrono::system_clock::now();
	std::time_t			currTime		= 0;
	int					memberNumber	= 0;
	int					providerNumber	= 0;
	std::stringstream	ss;
	Service				service;

	// Provider validation
	terminal.displayString("Provider Number: ");
	terminal.getIntInput(&providerNumber);
	provider = registration.getProvider(providerNumber);
	if (provider == nullptr)
	{
		terminal.displayString("Provider Number invalid\n");
		return;
	}

	// Member validation
	terminal.displayString("Member Number: ");
	terminal.getIntInput(&memberNumber);
	member = registration.getMember(memberNumber);
	if (member == nullptr)
	{
		terminal.displayString("Member Number invalid\n");
		return;
	}

	record = new ServiceRecord();
	record->providerNumber= providerNumber;
	record->memberNumber = memberNumber;

	// Get the current time and convert to local time
	currTime = std::chrono::system_clock::to_time_t(now);
#ifdef _WIN32
	std::tm localTime;
    localtime_s(&localTime, &currTime);
	ss << std::put_time(&localTime, "%m-%d-%Y %H:%M:%S");
#else
	ss << std::put_time(std::localtime(&currTime), "%m-%d-%Y %H:%M:%S");
#endif
	record->currTime = ss.str();

	terminal.getServiceRecordInput(record);
	// Separate function call to handle service code validation
	validateServiceCode(&service);

	// After the service code is validated, the service struct has valid data
	// so it can be added to the record.
	record->serviceCode = service.code;
	record->totalFee = service.fee;

	// Save the record to disk
	if (filesystem.saveServiceRecord(record))
	{
		terminal.displayString("Service Record Saved\n");
		// Add a copy of the service record to the Provider and Member lists
		provider->services.push_back(record);
		member->services.push_back(record);
	}
	else
	{
		terminal.displayString("Error creating service record.\n");
	}
}

/// <summary>
/// Prompts the user to enter a service code. If the code is valid, a summary of the service is
/// displayed to the Terminal, requesting the user confirm the information is correct.
/// </summary>
/// <param name="service">A pointer to the service struct. Is initialized on valid service code entry</param>
void DataCenter::validateServiceCode(Service* service)
{
	int serviceCode;

	do
	{
		do
		{
			terminal.displayString("Service Code: ");
			terminal.getIntInput(&serviceCode);

		} while (!filesystem.getServiceByCode(service, serviceCode));

		std::string display = (
			"Service: " + service->name + "\n" +
			"Fee: " + std::to_string(service->fee) + "\n" +
			"Is this correct (y/n): "
			);
		terminal.displayString(display);
	} while (!terminal.confirm());
}

/// <summary>
/// Edits a person struct via the Terminal.
/// </summary>
/// <param name="person">A Pointer to an existing person struct retireved from the Registration class</param>
void DataCenter::editPerson(Person* person)
{
	if (person != nullptr)
	{
		std::string personDisplay = (
			"Current Name: " + person->name + "\n" +
			"Current ID Number: " + std::to_string(person->number) + "\n" +
			"Current Address: " + person->address.addr + "\n" +
            "Current City: " + person->address.city + "\n" +
            "Current State: " + person->address.state + "\n" +
            "Current Zip Code: " + std::to_string(person->address.zip) + "\n"
		);
		terminal.displayString(personDisplay);
		terminal.getPersonInput(person);
	}
}

