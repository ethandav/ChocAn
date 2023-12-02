// Registration.cpp
// Implementation file for the Registration class, which handles the data structures for
// Providers and Members including insert, update, delete, validate, retrieve and dynamic memory management.

#include "Registration.h"
#include <iostream>

Registration::~Registration()
{
	while (!members.empty())
	{
		while (!members.front()->services.empty())
		{
			delete members.front()->services.front();
			members.front()->services.pop_front();
		}
		delete members.front();
		members.pop_front();
	}

	while (!providers.empty())
	{
		delete providers.front();
		providers.pop_front();
	}
}

/// <summary>
/// Inserts new member to member list
/// </summary>
/// <param name="member"> - A pointer to a new Person struct</param>
/// <returns>True on successful insert</returns>
bool Registration::registerMember(Person* member)
{
	if (member != nullptr && member->number)
	{
		if (findByNumber(members, member->number) == nullptr)	
		{	
			members.push_back(member);
			return true;
		}
		else
		{
			std::cerr << "Error: Duplicate member number '" << member->number << "' was detected.\n";
			return false;
		}
	}
	return false;
}

/// <summary>
/// Inserts a new provider to provider list
/// </summary>
/// <param name="provider"> - A Pointer to a new Person struct</param>
/// <returns>True on successful insert</returns>
bool Registration::registerProvider(Person* provider)
{
	if (provider != nullptr && provider->number)
	{
		if (findByNumber(providers, provider->number) == nullptr)
		{
			providers.push_back(provider);
			return true;
		}
		else
		{
			std::cerr << "Error: Duplicate provider number '" << provider->number << "' was detected.\n";
			return false;
		}
	}
	return false;
}

/// <summary>
/// Removes a member from the member list by the provided memberNumber
/// </summary>
/// <param name="memberNumber"> - An ID for an existing member</param>
/// <returns>True on successful removal</returns>
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

/// <summary>
/// Removes a provider from the provider list by the provided provider number
/// </summary>
/// <param name="providerNumber"> - An ID for an existing provider</param>
/// <returns>True on successful removal</returns>
bool Registration::removeProvider(const int providerNumber)
{
	Person* target = findByNumber(providers, providerNumber);
	if (target != nullptr)
	{
		providers.remove(target);
		delete target;
		return true;
	}
	return false;
}

/// <summary>
/// Searches the member list to determine if the provided memberNumber is valid
/// </summary>
/// <param name="memberNumber"> - A user provided member number</param>
/// <returns>True if the member number exists in the member list</returns>
bool Registration::validateMemberCard(int memberNumber)
{
	if (findByNumber(members, memberNumber) != nullptr)
		return true;
	else
		return false;
}

/// <summary>
/// Retrieves a Person struct from the member list by memberNumber
/// </summary>
/// <param name="memberNumber"> - A user provided member number</param>
/// <returns>A Pointer to the retrieved member, or a nullptr</returns>
Person* Registration::getMember(int memberNumber)
{
	return findByNumber(members, memberNumber);
}

/// <summary>
/// Retrieves a Person struct from the provider list by providerNumber
/// </summary>
/// <param name="providerNumber"> - A user provided provider number</param>
/// <returns>A Pointer to the retrieved provider, or a nullptr</returns>
Person* Registration::getProvider(int providerNumber)
{
	return findByNumber(providers, providerNumber);
}

// Temp  Getters for Reports Class
const std::list<Person*>& Registration::getMemberList() const
{
	return members;
}
const std::list<Person*>& Registration::getProviderList() const
{
	return providers;
}

/// <summary>
/// Searches a person list for the provided number
/// </summary>
/// <param name="list"> - Either a member list or provider list</param>
/// <param name="number"> - A number to search for in the list</param>
/// <returns>Pointer to the found Person, or nullptr</returns>
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

