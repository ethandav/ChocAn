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
	void validateMember();
	void getProviderDirectory();

private:
	// Registration
	bool updateMember(Person* member);
	bool updateProvider(Person* provider);

	//Reports
	void generateMemberReport();
	void generateProviderReport();
	void generateSummaryReport();

	// Filesystem
	bool saveServiceRecord();

	Terminal terminal;
	Registration registration;
	Filesystem filesystem;
	Reports reports;
};
