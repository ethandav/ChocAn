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
	void clearScreen();
private:
	bool running;
	bool isAdmin;
	DataCenter* dc;

	void displayLogin();
	void adminTerminal();
	void providerTerminal();
	void displayAdminMenu();
	void displayProviderMenu();
	void waitForAny();
	void flushInput();
};
