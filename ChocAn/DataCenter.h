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
	void updateMember();
	void updateProvider();
	void removeMember();
	void removeProvider();
	void validateMember();
	void getProviderDirectory();

private:
	void editPerson(Person* person);

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
