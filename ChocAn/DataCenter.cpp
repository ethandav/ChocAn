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

}

void DataCenter::generateProviderReport()
{

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
	ServiceRecord*	record			= nullptr;
	Person*			provider		= nullptr;
	Person*			member			= nullptr;
	int				memberNumber	= 0;
	int				providerNumber	= 0;

	terminal.displayString("Provider Number: ");
	terminal.getIntInput(&providerNumber);
	provider = registration.getMember(providerNumber);
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
	
	terminal.getServiceRecordInput(record);
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
