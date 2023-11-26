#pragma once
#include "Terminal.h"
#include "Registration.h"
#include "Filesystem.h"
#include "Reports.h"
#include "Person.h"

class DataCenter
{
public:
	DataCenter() {};
	~DataCenter() {};

	void start();
	void registerMember();
	void registerProvider();
	void removeMember();
	void removeProvider();

private:
	// Registration
	bool updateMember(Person* member);
	bool updateProvider(Person* provider);
	bool validateMember(int memberNumber);

	//Reports
	void generateMemberReport();
	void generateProviderReport();
	void generateSummaryReport();

	// Filesystem
	std::string getProviderDirectory();
	bool saveServiceRecord();

	Terminal terminal;
	Registration registration;
	Filesystem filesystem;
	Reports reports;
};
