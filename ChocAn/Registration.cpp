#include "Registration.h"
#include <iostream>

Registration::~Registration()
{
	while (!members.empty())
	{
		delete members.front();
		members.pop_front();
	}

	while (!providers.empty())
	{
		delete providers.front();
		providers.pop_front();
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
	if(provider != nullptr){
		providers.push_back(provider);
		return true;
	}
	return false;
}

bool Registration::removeMember(const int memberNumber)
{
	Person* target = findByNumber(members, memberNumber);
	if (target != nullptr)
	{
		members.remove(target);
		delete target;
		return true;
	}
	return false;
}

bool Registration::removeProvider(const int providerNumber)
{
	Person* target = findByNumber(members, providerNumber);
	if (target != nullptr)
	{
		members.remove(target);
		delete target;
		return true;
	}
	return false;
}

bool Registration::validateMemberCard(int memberNumber)
{
	if (findByNumber(members, memberNumber) != nullptr)
		return true;
	else
		return false;
}

Person* Registration::getMember(int memberNumber)
{
	return findByNumber(members, memberNumber);
}

Person* Registration::getProvider(int providerNumber)
{
	return findByNumber(members, providerNumber);
}

Person* Registration::findByNumber(const std::list<Person*>& list, int number)
{
	for (const auto& ptr : list)
	{
		if (ptr->number == number)
		{
			return ptr;
		}
	}
	return nullptr;
}

bool Registration::editPerson(Person* person)
{
	return false;
}
