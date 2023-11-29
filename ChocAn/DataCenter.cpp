#include "DataCenter.h"

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

// Registration
void DataCenter::registerMember()
{
	Person* newMember = new Person();
	terminal.getPersonInput(newMember);

	if (registration.registerMember(newMember))
	{
		terminal.displayString("Member succesfully Added!\n");
	}
}

/* ignore this, this is so I can test - Aaron
void DataCenter::registerMember() {
    Person hardcodedMembers[4];

    hardcodedMembers[0].name = "John Doe";
    hardcodedMembers[0].number = 123456789;
    hardcodedMembers[0].address.addr = "123 Main St";
    hardcodedMembers[0].address.city = "Anytown";
    hardcodedMembers[0].address.state = "NY";
    hardcodedMembers[0].address.zip = 12345;

    hardcodedMembers[1].name = "Jane Smith";
    hardcodedMembers[1].number = 987654321;
    hardcodedMembers[1].address.addr = "456 Elm St";
    hardcodedMembers[1].address.city = "Othertown";
    hardcodedMembers[1].address.state = "CA";
    hardcodedMembers[1].address.zip = 54321;

    hardcodedMembers[2].name = "Alice Johnson";
    hardcodedMembers[2].number = 111222333;
    hardcodedMembers[2].address.addr = "789 Oak Rd";
    hardcodedMembers[2].address.city = "Sometown";
    hardcodedMembers[2].address.state = "TX";
    hardcodedMembers[2].address.zip = 67890;

    hardcodedMembers[3].name = "Bob Brown";
    hardcodedMembers[3].number = 444555666;
    hardcodedMembers[3].address.addr = "321 Pine Ln";
    hardcodedMembers[3].address.city = "Yettown";
    hardcodedMembers[3].address.state = "FL";
    hardcodedMembers[3].address.zip = 24680;

    for (int i = 0; i < 4; ++i) {
        Person* newMember = new Person(hardcodedMembers[i]);

        if (registration.registerMember(newMember)) {
            terminal.displayString("Member successfully Added!\n");
        } else {
            delete newMember;
        }
    }
}
*/

void DataCenter::registerProvider()
{
	Person* newProvider = new Person();
	terminal.getPersonInput(newProvider);

	if (registration.registerProvider(newProvider))
	{
		terminal.displayString("Provider succesfully Added!\n");
	}
}



void DataCenter::updateMember()
{
	int memberNumber = 0;
	Person* person = nullptr;

	terminal.displayString("Member Number: ");
	terminal.getIntInput(&memberNumber);

	person = registration.getMember(memberNumber);
	if (person == nullptr)
	{
		terminal.displayString("Member not found\n");
		return;
	}

	editPerson(person);
}

void DataCenter::updateProvider()
{
	int providerNumber = 0;
	Person* person = nullptr;

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
	//providers refers to std::list<Provider>& providers
	/*
	if(reports.generateProviderReports(providers))
	{
		terminal.displayString("Provider Report Generation Success\n");
	}
	else
	{
		terminal.displayString("Provider Report Generation Failed\n");
	}
	*/
}

void DataCenter::generateSummaryReport()
{

}

// Filesystem
void DataCenter::getProviderDirectory()
{
	terminal.displayString(filesystem.getProviderDirectory());
}

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

	terminal.displayString("Provider Number: ");
	terminal.getIntInput(&providerNumber);
	provider = registration.getProvider(providerNumber);
	if (provider == nullptr)
	{
		terminal.displayString("Provider Number invalid\n");
		return;
	}

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

	currTime = std::chrono::system_clock::to_time_t(now);

#ifdef _WIN32
	std::tm localTime;
    localtime_s(&localTime, &currTime);
    ss << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");
#else
    //ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
    ss << std::put_time(std::localtime(&currTime), "%Y-%m-%d %H:%M:%S");
#endif

	record->currTime = ss.str();
	
	terminal.getServiceRecordInput(record);
	if (filesystem.saveServiceRecord(record))
	{
		terminal.displayString("Service Record Saved\n");
		provider->services.push_back(record);
		member->services.push_back(record);
	}
	else
	{
		terminal.displayString("Error creating service record.\n");
	}
}

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
