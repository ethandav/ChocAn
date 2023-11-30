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

	// TEMP GETTERS TO GENERATE REPORTS, we can figure out another way later if need be
	const std::list<Person*>& getMemberList() const;
	const std::list<Person*>& getProviderList() const;

private:
	std::list<Person*> members;
	std::list<Person*> providers;
	
	Person* findByNumber(const std::list<Person*>& list, int number);
};
