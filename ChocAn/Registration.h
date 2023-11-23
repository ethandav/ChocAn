#pragma once
#include <list>
#include <string>

#include "Person.h"

class Registration
{
public:
	Registration() {};
	~Registration() {};
	void registerMember(Person* member);
	void registerProvider(Person* provider);
	void removeMember(int cardNumber);
	void removeProvider(int providerNumber);
	bool validateMemberCard(int memberNumber);

private:
	std::list<Person*> members;
	std::list<Person*> providers;
};
