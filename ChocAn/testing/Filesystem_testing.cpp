#include <cassert>
#include <string>

#include "../ChocAn.h"
#include "../Filesystem.h"

int main() {
	// Test getProviderDirectory
	{
		Filesystem fs;
		std::string result = fs.getProviderDirectory();
		assert(result != "Provider Directory Unavailable\n" && "getProviderDirectory test failed");
	}
	
	// Test getServiceByCode
	{
		Filesystem fs;
		Service service;
		bool result = fs.getServiceByCode(&service, 123);
		assert(result == false && "getServiceByCode test failed");
	}
	
	// Test saveServiceRecord
	{
		Filesystem fs;
		ServiceRecord record;
		record.currTime = "12/1/2023";
		record.servTime = "12/1/2023";
		record.memberNumber = 12345;
		record.providerNumber = 67890;
		record.serviceCode = 12345;
		record.totalFee = 12.00;
		record.comments = "Test";
		bool result = fs.saveServiceRecord(&record);
		assert(result == true && "saveServiceRecord test failed");
	}
	
	// Test saveReportToFile
	{
		Filesystem fs;
		std::string subDirectory = "test";
		std::string filename = "test.txt";
		std::string reportData = "Test Report Data";
		bool result = fs.saveReportToFile(subDirectory, filename, reportData);
		assert(result == true && "saveReportToFile test failed");
	}

	std::cout << "All Test Passed!" << std::endl;

	return 0;
}

