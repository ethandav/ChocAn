#pragma once
#include <string>
#include <list>
#include <iostream>
#include "ChocAn.h"
#include "Registration.h"

/* Header file to generate Member and Provider reports */
class Reports
{
public:
	Reports() {};
	~Reports() {};
	// Weekly reports
	bool generateMemberReports(const std::list<Member>& members);	
	bool generateProviderReports(const std::list<Provider>& providers);	
	// Manual reports
	bool generateMemberReportByID(const std::list<Member>& members, int memberID);
	bool generateProviderReportByID(const std::list<Provider>& providers, int providerID);

private:
	// Helper functions
	//Member * findMember(const std::string& id);
	//Provider * findProvider(const std::string& id);

	//bool LastWeekRange(const std::string & serviceDate);	// Weekly report range
	//std::string formatMemberDetails(const Person& member);			
	//std::string formatProviderDetails(const Person& provider);
	//std::string formatServiceRecord(const ServiceRecord& record);		

};
