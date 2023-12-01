#include <iostream>
#include <cassert>
#include "../ChocAn.h"
#include "../Registration.h"

int main() {
	Registration registration;

	// Test Case 1: Register a member
	{
		// Happy
		{
			Person* member = new Person("John Doe", 123456789, "123 Main St", "City", "CA", 12345);
			assert(registration.registerMember(member));
		}
		// Sad
		{
			Person* member = new Person();
			assert(registration.registerMember(member) == false && "Invalid Member Registration Test Failed");
			delete member;
		}
	}
	
	// Test Case 2: Validate member card
	{
		// Happy
		{
			assert(registration.validateMemberCard(123456789));
		}
		// Sad
		{
			assert(registration.validateMemberCard(987654321) == false);
		}
	}
	
	// Test Case 3: Get member by number
	{
		// Happy
		{
			Person* retrievedMember = registration.getMember(123456789);
			assert(retrievedMember != nullptr && retrievedMember->number == 123456789);
		}
		// Sad
		{
			Person* retrievedMember = registration.getMember(987654321);
			assert(retrievedMember == nullptr && "Invalid Member Retrieval Test Failed");
		}
	}
	
	// Test Case 4: Register a provider
	{
		// Happy
		{
			Person* provider = new Person("Dr. Smith", 987654321, "456 Oak St", "City", "CA", 54321);
			assert(registration.registerProvider(provider));
		}
		// Sad
		{
			Person* provider = new Person();
			assert(registration.registerProvider(provider) == false && "Invalid Provider Registration Test Failed");
			delete provider;
		}
	}
	
	// Test Case 5: Remove member
	{
		// Happy
		{
			assert(registration.removeMember(123456789));
			assert(registration.getMember(123456789) == nullptr);
		}
		// Sad
		{
			assert(registration.removeMember(987654321) == false && "Invalid Member Removal Failed");
		}
	}
	
	// Test Case 6: Remove provider
	{
		// Happy
		{
			assert(registration.removeProvider(987654321));
			assert(registration.getProvider(987654321) == nullptr);
		}
		// Sad
		{
			assert(registration.removeProvider(123456789) == false && "Invalid Provider Removal Failed");
		}
	}
	
	std::cout << "All tests passed successfully!" << std::endl;
	
	return 0;
}
