#include "Reports.h"
#include <iomanip>
#include <chrono>
#include <ctime>

/* Reports class member function implementation */
bool Reports::generateMemberReports(const std::list<Person*>& members, Registration& registration, Filesystem& filesystem) 
{
    std::stringstream report;
    if (!members.empty())
    {
    	for (auto memberPtr : members) {
            std::string memberReport = formatMemberDetails(*memberPtr);
            report << memberReport << std::endl;

            for (auto servicePtr : memberPtr->services) {
                if (servicePtr) {
                    // date of service (servTime)
                    const std::string dateOfService = servicePtr->servTime;

                    // Provider name
                    Person* provider = registration.getProvider(servicePtr->providerNumber);
                    const std::string providerName = provider->name;

                    // Service name
                    const std::string serviceName = filesystem.getServiceByCode(servicePtr->serviceCode)->name;

                    std::string serviceReport = formatServiceShort(dateOfService, providerName, serviceName);
                    report << serviceReport << std::endl;
                }
            }
        }
        return true;
    }
    else
        return false;
}

bool Reports::generateProviderReports(const std::list<Person*>& providers)
{
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
std::string Reports::formatServiceShort(const std::string dateOfService, const std::string providerName, const std::string serviceName) {
	std::stringstream ss;
	ss << "Service Date: " << dateOfService << "\n" 
		<< "Provider Number: " << providerName << "\n"
		<< "Member Number: " << serviceName << "\n";
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

const std::string findProvider(const std::list<Person*>& members, int id)
{
    for (auto memberPtr : members) { 
        if (memberPtr->number == id) return memberPtr->name;
    }
    return "";
}

