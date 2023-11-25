#pragma once
#include <iostream>

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
	void displayString(std::string displayStr);
private:
	bool running;
	DataCenter* dc;

	void displayMenu();
	void getInputInt(int* input);
	void flushInput();
};
