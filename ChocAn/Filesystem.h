#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Filesystem
{
public:
	Filesystem() {};
	~Filesystem() {};

	std::string getProviderDirectory();

private:
	bool openFile(std::ifstream& fs, const std::string& filename);
	bool readFile(std::ifstream& fs);
	bool closeFile(std::ifstream& fs);
	std::string parseContents();

	std::vector<std::string> fileContents;
};
