#pragma once
#include <iostream>
#include <string>
#include "Registration.h" // For Person struct

using namespace std;

class Terminal
{
public:
	Terminal() {};
	~Terminal() {};

	void open();
private:
	bool running;

	void displayMenu();
	void getInputInt(int* code);
	void getInputString(string* input);
	void enterPatientName();
	void enterMemberCardData();
	void enterServiceCode();
	void displayPatient();
	

};
