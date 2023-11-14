#pragma once
#include <iostream>

class Terminal
{
public:
	Terminal() {};
	~Terminal() {};

	void open();
private:
	bool running;

	void displayMenu();
	void getInputInt(int* input);
};
