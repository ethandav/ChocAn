#include "Registration.h"

void Registration::registerMember(Person* member)
{
	members.push_back(member);
}

void Registration::registerProvider(Person* provider)
{
	providers.push_back(provider);
}

void Registration::removeMember(int cardNumber)
{
	// Remove from member list by number
}

void Registration::removeProvider(int providerNumber)
{
	// Remove from provider list by number
}

bool Registration::validateMemberCard(int memberNumber)
{
	bool valid = false;

	// Check member list for member number

	return valid;
}
