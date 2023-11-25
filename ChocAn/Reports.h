#pragma once
#include <string>
#include <list>
#include <iostream>
#include "Registration.h"

class Reports
{
public:

	Reports() {};
	~Reports() {};
	// weekly reports
	void generateMemberReports(const std::list<Member>& members);	
	void generateProviderReports(const std::list<Provider>& providers);	
	// manual reports
	void generateMemberReportById(const std::list<Member>& members, const std::string & memberId);
	void generateProviderReportById(const std::list<Provider>& providers, const std::string& providerId);


private:
	// helper functions for generateReportById
	Member * findMember(const std::string& id);
	Provider * findProvider(const std::string& id);

};
