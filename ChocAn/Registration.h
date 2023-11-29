#pragma once
#include "ChocAn.h"

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
	Person* getMember(int memberNumber);
	Person* getProvider(int providerNumber);

private:
	std::list<Person*> members;
	std::list<Person*> providers;
	
	Person* findByNumber(const std::list<Person*>& list, int number);
	bool editPerson(Person* person);
};
