#include "DataCenter.h"

void DataCenter::start()
{
	terminal.open();
}

// Registration
bool registerMember(Person& member)
{
	return false;
}

bool registerProvider(Person& provider)
{
	return false;
}

bool updateMember(Person& member)
{
	return false;
}

bool updateProvider(Person& provider)
{
	return false;
}

bool removeMember(int memberNumber)
{
	return false;
}

bool removeProvider(int providerNumber)
{
	return false;
}

bool validateMember(int memberNumber)
{
	return false;
}

//Reports
void generateMemberReport()
{

}

void generateProviderReport()
{

}

void generateSummaryReport()
{

}

// Filesystem
std::string getProviderDirectory()
{
	return "Provider Directory";
}

bool saveServiceRecord()
{
	return false;
}
