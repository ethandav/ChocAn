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
};

struct Service
{
	int code;
	std::string name;
	int fee;
};
