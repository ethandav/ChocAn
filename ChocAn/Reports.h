#pragma once
#include <string>
#include <list>
#include <iostream>
#include "Registration.h"

/* Header file to generate Member and Provider reports */

class Reports
{
public:

	Reports() {};
	~Reports() {};
	// weekly reports
	bool generateMemberReports(const std::list<Member>& members);	
	bool generateProviderReports(const std::list<Provider>& providers);	
	// manual reports
	bool generateMemberReportById(const std::list<Member>& members, const std::string& memberId);
	bool generateProviderReportById(const std::list<Provider>& providers, const std::string& providerId);


private:
	// helper functions for generateReportById
	Member * findMember(const std::string& id);
	Provider * findProvider(const std::string& id);

};
