#pragma once
#include <list>
#include <string>

struct Address
{
	std::string addr;
	std::string city;
	std::string state;
	int			zip;
};

struct Person
{
	std::string name;
	Address		address;
	int			number;
};

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
