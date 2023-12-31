#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <filesystem>

#include "ChocAn.h"

class Filesystem
{
public:
	Filesystem() {};
	~Filesystem() {};

	std::string getProviderDirectory();
	void loadPeople(std::vector<std::string>& people, std::string file);
	bool savePersonToCsv(Person* person, std::string file);
	bool updatePersonFiles(std::list<Person*> people, std::string file);
	bool getServiceByCode(Service* service, int lookupCode);
	bool saveServiceRecord(ServiceRecord* record);
	bool saveReportToFile(const std::string& subDirectory, const std::string& filename, const std::string& reportData);

private:
	bool openFile(std::ifstream& fs, const std::string& filename);
	bool readFile(std::ifstream& fs);
	bool closeFile(std::ifstream& fs);
	std::string parseContents();

	std::vector<std::string> fileContents;
};
