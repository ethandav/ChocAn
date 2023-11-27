#include "Filesystem.h"

std::string Filesystem::getProviderDirectory()
{
	std::ifstream fs;
	if (!openFile(fs, "./filesystem/providerDirectory.csv"))
	{
		return "Provider Directory Unavailable\n";
	}

	if (!readFile(fs))
	{
		return "Provider Directory Unavailable\n";
	}

	closeFile(fs);

	return parseContents();
}

bool Filesystem::saveServiceRecord(ServiceRecord* record)
{
	std::string fn = "./filesystem/Service_" + std::to_string(record->serviceCode) + "_" + std::to_string(record->memberNumber);
	std::ofstream of(fn);

	if (of.is_open())
	{
		of << record->currTime + "\n";
		of << record->servTime + "\n";
		of << std::to_string(record->memberNumber) + "\n";
		of << std::to_string(record->providerNumber) + "\n";
		of << std::to_string(record->serviceCode) + "\n";
		of << std::to_string(record->totalFee) + "\n";
		of << record->comments << std::endl;

		of.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool Filesystem::openFile(std::ifstream& fs, const std::string& filename)
{
	fs.open(filename);
	if (!fs.is_open())
	{
		std::cerr << "Error: Unable to open file: " << filename << std::endl;
		return false;
	}
	return true;
}

bool Filesystem::readFile(std::ifstream& fs)
{
	std::string line = "";

	if (!fs.is_open())
	{
		std::cerr << "Error: File is not open" << std::endl;
		return false;
	}

	while (std::getline(fs, line))
	{
		fileContents.push_back(line);
	}
	return true;
}

bool Filesystem::closeFile(std::ifstream& fs)
{
	if (fs.is_open())
	{
		fs.close();
		return true;
	}
	else
	{
		std::cerr << "Error: File is not open" << std::endl;
		return false;
	}
}

std::string Filesystem::parseContents()
{
	std::string contents = "";
	for (const auto& line : fileContents)
	{
		contents += line + "\n";
	}

	return contents;
}
