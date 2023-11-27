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

// Temp stub

bool Reports::generateMemberReportById(const std::list<Member>& members, const std::string& memberId) {
    if(!members)
        return false;
    return true;
}

bool Reports::generateProviderReportById(const std::list<Provider>& providers, const std::strings& providerId) {
    if(!providers)
        return false;
    return true;
}
