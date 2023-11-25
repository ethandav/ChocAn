#include "Registration.h"
#include <iostream>

Registration::~Registration()
{
	while (!members.empty())
	{
		delete members.front();
		members.pop_front();
	}
}

bool Registration::registerMember(Person* member)
{
	if(member != nullptr){
		members.push_back(member);
		return true;
	}
	return false;
}

bool Registration::registerProvider(Person* provider)
{
	providers.push_back(provider);
	return false;
}

bool Registration::removeMember(int cardNumber)
{
	// Remove from member list by number
	return false;
}

bool Registration::removeProvider(int providerNumber)
{
	// Remove from provider list by number
	return false;
}

bool Registration::validateMemberCard(int memberNumber)
{
	bool valid = false;

	// Check member list for member number

	return valid;
}
