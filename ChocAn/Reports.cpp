#include "Reports.h"
#include <iomanip>
#include <chrono>
#include <ctime>

/* Reports class member function implementation */
bool Reports::generateMemberReports(const std::list<Person*>& members) {
    std::stringstream report;
    if (!members.empty())
    {
    	for (auto memberPtr : members) {
            
        }
        /*for (auto member : members) {
            //cout << members.person.name << endl;
        }*/
        return true;
    }
    else
        return false;
}

bool Reports::generateProviderReports(const std::list<Person*>& providers) {
    if (!providers.empty())
    {
        /*for (auto provider : providers) {
            //cout << providers.person.name << endl;
        }*/
        return true;
    }
    else
        return false;
}

bool Reports::generateMemberReportByID(const std::list<Person*>& members, int memberID) {
    if (members.empty())
        return false;
    return true;
}

bool Reports::generateProviderReportByID(const std::list<Person*>& providers, int providerID) {
    if (providers.empty())
        return false;
    return true;
}
/* bool Reports::LastWeekRange(const std::string & serviceDate) {
} */

std::string Reports::formatMemberDetails(const Person& member) {
	std::stringstream ss;
	ss << "Member Name: " << member.name << "\n"
		<< "Member Number: " << member.number << "\n"
		<< "Address: " << member.address.addr << "\n" 
		<< member.address.city << ", " << member.address.state 
		<< " " << member.address.zip << "\n";
	return ss.str();
}

std::string Reports::formatProviderDetails(const Person& provider) {
	std::stringstream ss;
	ss << "Provider Name: " << provider.name << "\n"
		<< "Provider Number: " << provider.number << "\n"
		<< "Address: " << provider.address.addr << "\n" 
		<< provider.address.city << ", " << provider.address.state 
		<< " " << provider.address.zip << "\n";
	return ss.str();
}
std::string Reports::formatServiceRecord(const ServiceRecord& record) {
	std::stringstream ss;
	ss << "Service Date: " << record.servTime << "\n"		// (MM-DD-YYYY)
		<< "Provider Number: " << record.providerNumber << "\n"	// Provider name? (25 characters)
		<< "Member Number: " << record.memberNumber << "\n" 
		<< "Service Code: " << record.serviceCode << "\t" 	// Service name? (20 characters)
		<< "Fee: $" << std::fixed << std::setprecision(2) << record.totalFee << "\n"
		<< "Comments: " << record.comments << "\n";
	return ss.str();
}

