#include "Reports.h"
using namespace std;

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