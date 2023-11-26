#pragma once
#include <list>
#include <string>

#include "Person.h"

class Registration
{
public:
	Registration() {};
	~Registration();
	bool registerMember(Person* member);
	bool registerProvider(Person* provider);
	bool removeMember(const int memberNumber);
	bool removeProvider(const int providerNumber);
	bool validateMemberCard(int memberNumber);

private:
	std::list<Person*> members;
	std::list<Person*> providers;
	
	Person* findByNumber(const std::list<Person*>& list, int number);
};
