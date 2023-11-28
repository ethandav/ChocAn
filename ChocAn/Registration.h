#pragma once
#include <list>
#include <string>

#include "ChocAn.h"

struct Member
{
	Person person;
	// List of services taken
};

struct Provider 
{
	Person person;
	// List of services given
};

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
