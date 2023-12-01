#include <iostream>
#include <cassert>
#include "../ChocAn.h"
#include "../Registration.h"

int main() {
    // Test Case 1: Register a member
    Registration registration;
    Person* member = new Person("John Doe", 123456789, "123 Main St", "City", "CA", 12345);
    assert(registration.registerMember(member));

    // Test Case 2: Validate member card
    assert(registration.validateMemberCard(123456789));

    // Test Case 3: Get member by number
    Person* retrievedMember = registration.getMember(123456789);
    assert(retrievedMember != nullptr && retrievedMember->number == 123456789);

    // Test Case 4: Register a provider
    Person* provider = new Person("Dr. Smith", 987654321, "456 Oak St", "City", "CA", 54321);
    assert(registration.registerProvider(provider));

    // Test Case 5: Remove member
    assert(registration.removeMember(123456789));
    assert(registration.getMember(123456789) == nullptr);

    // Test Case 6: Remove provider
    assert(registration.removeProvider(987654321));
    assert(registration.getProvider(987654321) == nullptr);

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}
