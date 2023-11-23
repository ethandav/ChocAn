#pragma once
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

