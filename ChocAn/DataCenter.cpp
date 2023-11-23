#include "DataCenter.h"

void DataCenter::start()
{
	terminal.open();
}

// Registration
bool DataCenter::registerMember(Person& member)
{
	return false;
}

bool DataCenter::registerProvider(Person& provider)
{
	return false;
}

bool DataCenter::updateMember(Person& member)
{
	return false;
}

bool DataCenter::updateProvider(Person& provider)
{
	return false;
}

bool DataCenter::removeMember(int memberNumber)
{
	return false;
}

bool DataCenter::removeProvider(int providerNumber)
{
	return false;
}

bool DataCenter::validateMember(int memberNumber)
{
	return false;
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
