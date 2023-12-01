#pragma once
#include <string>
#include <list>

struct ServiceRecord
{
	std::string	currTime;
	std::string	servTime;
	int			providerNumber;
	int			memberNumber;
	int			serviceCode;
	float		totalFee;
	std::string comments;
};

struct Address
{
	std::string addr;
	std::string city;
	std::string state;
	int			zip;
};

struct Person
{
	std::string					name;
	Address						address;
	int							number;
	std::list<ServiceRecord*>	services;

	Person() {};
	Person(
		std::string aName,
		int			aNumber,
		std::string aStreet,
		std::string aCity,
		std::string aState,
		int			aZip
	) : name(aName), number(aNumber)
	{
		address.addr = aStreet;
		address.city = aCity;
		address.state = aState;
		address.zip = aZip;
	}
};

struct Service
{
	int code;
	std::string name;
	int fee;
};
