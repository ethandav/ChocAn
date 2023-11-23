#pragma once
#include <list>
#include <string>

#include "Person.h"

class Registration
{
public:
	Registration() {};
	~Registration() {};
	bool registerMember(Person* member);
	bool registerProvider(Person* provider);
	bool removeMember(int cardNumber);
	bool removeProvider(int providerNumber);
	bool validateMemberCard(int memberNumber);

private:
	std::list<Person*> members;
	std::list<Person*> providers;
};
