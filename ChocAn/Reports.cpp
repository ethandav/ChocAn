#include "Reports.h"
#include <iomanip>
#include <chrono>
#include <ctime>

/* Reports class member function implementation */
bool Reports::generateMemberReports(const std::list<Person*>& members, Registration& registration, Filesystem& filesystem) 
{
    if (!members.empty())
    {
        std::string currentDate = getCurrentDate();

    	for (const auto& memberPtr : members) 
        {
            if (!memberPtr) continue;
            std::stringstream report; 

            report << formatMemberDetails(*memberPtr) << "\n";
            for (const auto& servicePtr : memberPtr->services) 
            {
                if (servicePtr) 
                {
                    Service service;
                    if (!filesystem.getServiceByCode(&service, servicePtr->serviceCode)) continue;

                    // Date of service (servTime)
                    const std::string dateOfService = servicePtr->servTime;

                    // Provider name
                    Person* provider = registration.getProvider(servicePtr->providerNumber);
                    const std::string providerName = provider->name;

                    // Service name
                    const std::string serviceName = service.name;

                    report << formatServiceMember(dateOfService, providerName, serviceName) << std::endl;
                }
            }
            
            std::string filename = memberPtr->name + "_" + currentDate + ".txt";
            if (!filesystem.saveReportToFile("members", filename, report.str()))
            {
                return false;
            }
        }
        return true;
    }
    else
        return false;
}


bool Reports::generateProviderReports(const std::list<Person*>& providers, Registration& registration, Filesystem &filesystem)
{
    if (!providers.empty())
    {
        std::string currentDate = getCurrentDate();

    	for (const auto& providerPtr : providers) 
        {
            if (!providerPtr) continue;
            std::stringstream report;
            report << formatProviderDetails(*providerPtr) << std::endl;

            float totalFee = 0.0;
            int numberOfConsultations = providerPtr->services.size();

            for (const auto& servicePtr : providerPtr->services) 
            {
                if (servicePtr) 
                {
                    // Member name
                    Person* member = registration.getMember(servicePtr->memberNumber);
                    std::string memberName = member->name;
                    if (!member) {
                        std::cout << "Member Name not Found" << std::endl;
                        memberName = "N/A";
                    }
                    else  
                        memberName = member->name;

                    report << formatServiceProvider(*servicePtr, memberName, totalFee) << std::endl;
                }
            }
            report << "Number of Consultations: " << numberOfConsultations << std::endl;
            report << "Total Fee for the Week: $" << std::fixed << std::setprecision(2) << totalFee << std::endl;

            std::string filename = providerPtr->name + "_" + currentDate + ".txt";
            if (!filesystem.saveReportToFile("providers", filename, report.str()))
            {
                return false;
            }
            // Writing EFT
            if (totalFee > 0.0)
            {
                std::stringstream EFT;
                EFT << "Name: " << providerPtr-> name << "\n";
                EFT << "Provider Number: " << providerPtr->number << "\n";
                EFT << "Amount to be Transferred: " << totalFee << "\n";

                std::string filenameEFT = "EFT_" + providerPtr->name + "_" + currentDate + ".txt";
                if (!filesystem.saveReportToFile("EFT", filenameEFT, EFT.str()))
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}
bool Reports::generateSummaryReport(const std::list<Person*>& providers, Filesystem &filesystem)
{
    std::stringstream report;
    if (!providers.empty())
    {
        std::string currentDate = getCurrentDate();
        int totalProviders = 0;
        int totalConsultations = 0;
        float overallFees = 0.0;
    	for (const auto& providerPtr : providers) 
        {
            if (!providerPtr) continue;
            float providerEarnings = 0.0;
            bool madeMoney = false;

            for (const auto& servicePtr : providerPtr->services) 
            {
                if (servicePtr) 
                {
                    madeMoney = true;
                    totalConsultations += 1;
                    providerEarnings += servicePtr->totalFee;
                }
            }

            if (madeMoney) totalProviders += 1;
            overallFees += providerEarnings;

            report << "Name: " << providerPtr->name << "\n";
            report << "# of Consultations: " << providerPtr->services.size();
            report << "Total Fee for the Week: $" << std::fixed << std::setprecision(2) << providerEarnings << "\n";
        }
        report << "________________________________" << "\n";
        report << "Total # of Providers: " << totalProviders << "\n";
        report << "Total # of Consultations: " << totalConsultations << "\n";
        report << "Overall Combined Fees: " << std::fixed << std::setprecision(2) << overallFees << "\n";
        report << "________________________________" << "\n";

        std::string filename = "Manager_Summary_" + currentDate + ".txt";
        return filesystem.saveReportToFile("weekly", filename, report.str());
    }
    return false;
}

// Current date helper function
std::string Reports::getCurrentDate()
{
    std::stringstream date;
    auto now = std::chrono::system_clock::now();
    std::time_t currTime = std::chrono::system_clock::to_time_t(now);

#ifdef _WIN32
    std::tm localTime;
    localtime_s(&localTime, &currTime);
    date << std::put_time(&localTime, "%m-%d-%Y");
#else
    date << std::put_time(std::localtime(&currTime), "%m-%d-%Y");
#endif

    return date.str();
}
// Member detail format
std::string Reports::formatMemberDetails(const Person& member) 
{
	std::stringstream ss;
	ss << "Member Name: " << member.name << "\n"
		<< "Member Number: " << member.number << "\n"
		<< "Address: " << member.address.addr << "\n" 
		<< member.address.city << ", " << member.address.state 
		<< " " << member.address.zip << "\n";

	return ss.str();
}
// Provider detail format
std::string Reports::formatProviderDetails(const Person& provider) 
{
	std::stringstream ss;
	ss << "Provider Name: " << provider.name << "\n"
		<< "Provider Number: " << provider.number << "\n"
		<< "Address: " << provider.address.addr << "\n" 
		<< provider.address.city << ", " << provider.address.state 
		<< " " << provider.address.zip << "\n";

	return ss.str();
}

// Format helper for member reports
std::string Reports::formatServiceMember(const std::string dateOfService, const std::string providerName, const std::string serviceName) 
{
	std::stringstream ss;
	ss << "Service Date: " << dateOfService << "\n" 
		<< "Provider Name: " << providerName << "\n"
		<< "Service Name: " << serviceName << "\n";

	return ss.str();
}

// Format helper for provider reports
std::string Reports::formatServiceProvider(const ServiceRecord& record, std::string memberName, float &totalFee) 
{
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
