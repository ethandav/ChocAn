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
            Service service;

            report << memberReport << std::endl;

            for (auto servicePtr : memberPtr->services) {
                if (servicePtr) {
                
                    filesystem.getServiceByCode(&service, servicePtr->serviceCode);

                    // date of service (servTime)
                    const std::string dateOfService = servicePtr->servTime;

                    // Provider name
                    Person* provider = registration.getProvider(servicePtr->providerNumber);
                    const std::string providerName = provider->name;

                    // Service name
                    const std::string serviceName = service.name;

                    std::string serviceReport = formatServiceMember(dateOfService, providerName, serviceName);
                    report << serviceReport << std::endl;
                }
            }
        }
        return true;
    }
    else
        return false;
}

// bool Reports::generateProviderReports(const std::list<Person*>& providers)
bool Reports::generateProviderReports(const std::list<Person*>& providers, Registration& registration, Filesystem& filesystem)
{
    std::stringstream report;
    if (!providers.empty())
    {
    	for (auto providerPtr : providers) {
            std::string providerReport = formatProviderDetails(*providerPtr);
            report << providerReport << std::endl;

            float totalFee = 0.0;
            int numberOfConsultations = providerPtr->services.size();

            for (auto servicePtr : providerPtr->services) {
                if (servicePtr) {
                    // Provider name
                    Person* member = registration.getMember(servicePtr->memberNumber);
                    const std::string memberName = member->name;

                    std::string serviceReport = formatServiceProvider(*servicePtr, memberName, totalFee);
                    report << serviceReport << std::endl;
                }
            }
            report << "Number of Consultations: " << numberOfConsultations << std::endl;
            report << "Total Fee for the Week: $" << std::fixed << std::setprecision(2) << totalFee << std::endl;
        }
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

// this is for member reports
std::string Reports::formatServiceMember(const std::string dateOfService, const std::string providerName, const std::string serviceName) {
	std::stringstream ss;
	ss << "Service Date: " << dateOfService << "\n" 
		<< "Provider Number: " << providerName << "\n"
		<< "Member Number: " << serviceName << "\n";
	return ss.str();
}

// this is for provider reports
std::string Reports::formatServiceProvider(const ServiceRecord& record, std::string memberName, float &totalFee) {
	std::stringstream ss;
	ss << "Service Date: " << record.servTime << "\n"		// (MM-DD-YYYY)
        << "Date and Time Data: " << record.currTime << "\n" // (MM-DD-YYYY HH:MM:SS)
        << "Member Name: " << memberName << "\n"
		<< "Member Number: " << record.memberNumber << "\n" 
		<< "Service Code: " << record.serviceCode << "\n" 
		<< "Fee: $" << std::fixed << std::setprecision(2) << record.totalFee << "\n";
        totalFee += record.totalFee;
		// << "Comments: " << record.comments << "\n";
	return ss.str();
}
