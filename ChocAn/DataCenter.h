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
private:
	// Registration
	bool updateMember(Person* member);
	bool updateProvider(Person* provider);
	bool removeMember(int memberNumber);
	bool removeProvider(int providerNumber);
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
