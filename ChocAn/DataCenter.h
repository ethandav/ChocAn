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
	void registerMember();
	void registerProvider();
	void updateMember();
	void updateProvider();
	void removeMember();
	void removeProvider();
	void validateMember();
	void generateMemberReport();
	void generateProviderReport();
	void generateSummaryReport();
	void getProviderDirectory();
	void enterServiceRecord();

	bool registerMember(Person* person);
	bool registerProvider(Person* person);
	bool removeMember(const int& memberNumber);
	bool removeProvider(const int& providerNumber);
	bool validateMember(const int& memberNumber);
	bool enterServiceRecord(ServiceRecord* record);

private:
	void loadProviders();
	void loadMembers();
	void editPerson(Person* person);
	void validateServiceCode(Service* service);

	Terminal terminal;
	Registration registration;
	Filesystem filesystem;
	Reports reports;
};
