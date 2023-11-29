#pragma once
#include "ChocAn.h"
#include "Registration.h"
#include "Filesystem.h"

/* Header file to generate Member and Provider reports */
class Reports
{
public:
	Reports() {};
	~Reports() {};
	// Weekly reports
	bool generateMemberReports(const std::list<Person*>& members);	
	bool generateProviderReports(const std::list<Person*>& providers);	
	// Manual reports
	bool generateMemberReportByID(const std::list<Person*>& members, int memberID);
	bool generateProviderReportByID(const std::list<Person*>& providers, int providerID);

private:
	// Helper functions
	//Member * findMember(const std::string& id);
	//Provider * findProvider(const std::string& id);

	//bool LastWeekRange(const std::string & serviceDate);	// Weekly report range

	std::string formatMemberDetails(const Person& member);			
	std::string formatProviderDetails(const Person& provider);
	std::string formatServiceRecord(const ServiceRecord& record);		

};
