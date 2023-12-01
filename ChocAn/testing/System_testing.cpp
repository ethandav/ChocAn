#include <cassert>
#include <iostream>

#include "../DataCenter.h"

int main()
{
	DataCenter dc;

	// Test Case 1: Register a Member
	{
		// Happy
		{
			Person* member = new Person("John Doe", 123456789, "123 Main St", "City", "OR", 12345);
			assert(dc.registerMember(member));
		}
		// Sad
		{
			Person* member = new Person();
			bool result = dc.registerMember(member);
			assert(result == false && "Invalid Member Data Test Failed\n");
			delete member;
		}
	}

	// Test Case 2: Register a Provider
	{
		// Happy
		{
			Person* provider = new Person("John Doe", 123456789, "123 Main St", "City", "OR", 12345);
			assert(dc.registerProvider(provider));
		}
		// Sad
		{
			Person* provider = new Person();
			bool result = dc.registerProvider(provider);
			assert(result == false && "Invalid Provider Data Test Failed\n");
			delete provider;
		}
	}

	// Test Case 3: Validate Member
	{
		// Happy
		assert(dc.validateMember(123456789));
		// Sad
		assert(dc.validateMember(987654321) == false && "Invalid Member Card Test Failed");
	}

	// Test Case 4: Remove a Member
	{
		// Happy 
		assert(dc.removeMember(123456789));
		// Sad
		assert(dc.removeMember(987654321) == false && "Invalid Member Removal Test Failed");
	}

	// Test Case 5: Remove a Provider
	{
		// Happy
		assert(dc.removeProvider(123456789));
		// Sad
		assert(dc.removeProvider(987654321) == false && "Invalid Provider Removal Test Failed");
	}

	// Test Case 6: Enter Service Record
	{
		// Happy
		{
			ServiceRecord record;
			record.currTime = "12/1/2023";
			record.servTime = "12/1/2023";
			record.memberNumber = 12345;
			record.providerNumber = 67890;
			record.serviceCode = 12345;
			record.totalFee = 12.00;
			record.comments = "Test";
			assert(dc.enterServiceRecord(&record));
		}
		// Sad
		{
			ServiceRecord record;
			assert(dc.enterServiceRecord(&record) == false && "Invalid Service Record Test Failed");
		}
	}

	std::cout << "All tests Passed!" << std::endl;

	return 0;
}
