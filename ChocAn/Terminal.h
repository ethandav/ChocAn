#pragma once
#include <iostream>
#include <limits>

#include "ChocAn.h"

class DataCenter;

class Terminal
{
public:
	Terminal() {};
	~Terminal() {};

	void connect(DataCenter* dc);
	void open();
	void getPersonInput(Person* person);
	void getServiceRecordInput(ServiceRecord* record);
	void getIntInput(int* input);
	void displayString(std::string displayStr);
	void updatePersonData(Registration& registration, Person* person);
private:
	bool running;
	DataCenter* dc;

	void displayMenu();
	void flushInput();
};
