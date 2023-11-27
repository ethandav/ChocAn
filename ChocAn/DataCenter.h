#pragma once
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "Terminal.h"
#include "Registration.h"
#include "Filesystem.h"
#include "Reports.h"
#include "ChocAn.h"

class DataCenter
{
public:
	DataCenter() {};
	~DataCenter() {};

	void start();

	// Registration
	void registerMember();
	void registerProvider();
	void updateMember();
	void updateProvider();
	void removeMember();
	void removeProvider();
	void validateMember();

	// Reports
	void generateMemberReport();
	void generateProviderReport();
	void generateSummaryReport();

	// Filesystem
	void getProviderDirectory();
	void enterServiceRecord();

private:
	void editPerson(Person* person);

	Terminal terminal;
	Registration registration;
	Filesystem filesystem;
	Reports reports;
};
