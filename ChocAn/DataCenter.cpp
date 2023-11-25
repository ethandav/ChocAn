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

bool DataCenter::registerProvider(Person* provider)
{
	return registration.registerProvider(provider);
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
