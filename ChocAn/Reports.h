#pragma once
#include <string>
#include <list>

class Reports
{
public:

	Reports() {};
	~Reports() {};
	// weekly reports
	void generateMemberReports(const std::list<Member>& members);	
	void generateProviderReports(const std::list<Provider>& providers);	
	// manual reports
	void generateMemberReportById(const std::string & memberId);
	void generateProviderReportById(const std::string& providerId);


private:
	// helper functions for generateReportById
	Member * findMember(const std::string& id);
	Provider * findProvider(const std::string& id);

};
