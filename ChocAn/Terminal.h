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
	void getCharInput(char* input);
	void displayString(std::string displayStr);
	bool confirm();
private:
	bool running;
	DataCenter* dc;

	void displayMenu();
	void flushInput();
};
