//#include <sstream>
//#include <iomanip>
#include "Reports.h"
using namespace std;

/* Reports class member function implementation */

Reports::Reports() {	
}
Reports::~Reports() {
}
bool Reports::generateMemberReports(const std::list<Member>& members) {
    if(members)
    {
        for (auto member : members) {
            cout << member.person.name << endl;
        }
        return true;
    }
    else
        return false;
}

bool Reports::generateProviderReports(const std::list<Provider>& providers) {
    if(providers)
    {
        for (auto provider : providers) {
            cout << provider.person.name << endl;
        }
        return true;
    }
    else
        return false;
}

bool Reports::generateMemberReportByID(const std::list<Member>& members, int memberID) {
    if(!members)
        return false;
    return true;
}

bool Reports::generateProviderReportByID(const std::list<Provider>& providers, int providerID) {
    if(!providers)
        return false;
    return true;
}
/* bool Reports::LastWeekRange(const std::string & serviceDate) {
}

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
*/
