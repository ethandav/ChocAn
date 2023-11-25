#include "Reports.h"
using namespace std;

/* Reports class member function implementation */
Reports::Reports() {	
}
Reports::~Reports() {
}
void Reports::generateMemberReports(const std::list<Member>& members) {
    for (auto member : members) {
        cout << member.person.name << endl;
    }
}

void Reports::generateProviderReports(const std::list<Provider>& providers) {
    for (auto provider : providers) {
        cout << provider.person.name << endl;
    }
}

// Temp stub

void Reports::generateMemberReportById(const std::list<Member>& members, const std::string& memberId) {
}

void Reports::generateProviderReportById(const std::list<Provider>& providers, const std::strings& providerId) {
}
