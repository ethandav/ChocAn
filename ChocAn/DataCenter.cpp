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
		terminal.displayString("Member succesfully Added!");
	}
}

void DataCenter::registerProvider()
{
	Person* newProvider = new Person();
	terminal.getPersonInput(newProvider);

	if (registration.registerProvider(newProvider))
	{
		terminal.displayString("Provider succesfully Added!");
	}
}

bool DataCenter::updateMember(Person* member)
{
	return false;
}

bool DataCenter::updateProvider(Person* provider)
{
	return false;
}

bool DataCenter::removeMember(int memberNumber)
{
	return registration.removeMember(memberNumber);
}

bool DataCenter::removeProvider(int providerNumber)
{
	return registration.removeProvider(providerNumber);
}

bool DataCenter::validateMember(int memberNumber)
{
	return registration.validateMemberCard(memberNumber);
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
std::string DataCenter::getProviderDirectory()
{
	return "Provider Directory";
}

bool DataCenter::saveServiceRecord()
{
	return false;
}
