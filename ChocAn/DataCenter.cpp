#include "DataCenter.h"

void DataCenter::start()
{
	terminal.open();
}

// Registration
bool DataCenter::registerMember(Person* member)
{
	return registration.registerMember(member);
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
