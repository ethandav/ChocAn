#pragma once
#include <iostream>
#include <limits>

#include "Person.h"

class DataCenter;

class Terminal
{
public:
	Terminal() {};
	~Terminal() {};

	void connect(DataCenter* dc);
	void open();
	void getPersonInput(Person* person);
	void getIntInput(int* input);
	void displayString(std::string displayStr);
private:
	bool running;
	DataCenter* dc;

	void displayMenu();
	void flushInput();
};
