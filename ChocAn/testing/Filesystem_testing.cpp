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

		//Happy
		{
			assert(fs.getServiceByCode(&service, 657823));
		}
		// Sad
		{
			bool result = fs.getServiceByCode(&service, 123);
			assert(result == false && "getServiceByCode Invalid Code test failed");
		}
	}
	
	// Test saveServiceRecord
	{
		Filesystem fs;

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
			bool result = fs.saveServiceRecord(&record);
			assert(result == true && "saveServiceRecord test failed");
		}
		// Sad
		{
			ServiceRecord record;
			assert(fs.saveServiceRecord(&record) == false && "saveServiceRecord Empty Record Test failed");
		}
	}
	
	// Test saveReportToFile
	{
		Filesystem fs;
		
		// Happy
		{
			std::string subDirectory = "test";
			std::string filename = "test.txt";
			std::string reportData = "Test Report Data";
			bool result = fs.saveReportToFile(subDirectory, filename, reportData);
			assert(result == true && "saveReportToFile test failed");
		}
		// Sad
		{
			assert(fs.saveReportToFile("Test", "", "Test Report Data") == false && "saveReportToFile No Filename test failed");
			assert(fs.saveReportToFile("", "test.txt", "Test Report Data") == false && "saveReportToFile No Subdirectory test failed");
			assert(fs.saveReportToFile("Test", "test.txt", "") == false && "saveReportToFile No Report Content test failed");
		}
	}

	std::cout << "All Test Passed!" << std::endl;

	return 0;
}

