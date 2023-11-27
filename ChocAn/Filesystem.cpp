#include "Filesystem.h"

std::string Filesystem::getProviderDirectory()
{
	std::ifstream fs;
	if (!openFile(fs, "providerDirectory.csv"))
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
