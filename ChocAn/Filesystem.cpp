// Filesystem.cpp
// Implementation file for the Filesystem class, which handle all File I/O operations.

#include "Filesystem.h"

/// <summary>
/// Retrieves a directory of services from the disk that available to ChocAn Members through their providers
/// </summary>
/// <returns>The Service directory as a string</returns>
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

/// <summary>
/// Opens the provider directory and searches for the provided service code. If the service code is found
/// the provided pointer to a service struct is populated with the data.
/// </summary>
/// <param name="service"> - A Pointer to the service struct</param>
/// <param name="lookupCode"> - A user entered service code</param>
/// <returns>True on successful retrieval. False if no service is found by the code</returns>
bool Filesystem::getServiceByCode(Service* service, int lookupCode) 
{
	std::ifstream file;
	int currLine = 0;

	if (!openFile(file, "./filesystem/providerDirectory.csv"))
	{
		return false;
	}

	fileContents.clear(); 

	if (!readFile(file))
	{
		closeFile(file);
		return false;
	}

	for (const auto& line: fileContents)
	{
		std::stringstream ss(line);
		std::string serviceCode, serviceName, serviceFee;
		int code = 0;

		++currLine;
		if (currLine == 1)
		{
			continue; // Skip header of .csv file
		}

		std::getline(ss, serviceCode, ',');
		std::getline(ss, serviceName, ',');
		std::getline(ss, serviceFee, ',');

		try
		{
			code = std::stoi(serviceCode);
			if (code == lookupCode) 
			{
				closeFile(file);
				service->code = code;
				service->name = serviceName;
				service->fee = std::stof(serviceFee);
				return true;
			}
		}
		catch (const std::exception& e) 
		{
			continue;	// Skip invalid non-matching service codes
		}
	}

	closeFile(file);
	return false;
}

/// <summary>
/// Saves data from the provided ServiceRecord struct to disk
/// </summary>
/// <param name="record"> - A pointer to a ServiceRecord struct</param>
/// <returns>True on successful write. False if file is not open</returns>
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

/// <summary>
/// Opens a file
/// </summary>
/// <param name="fs"> - The file stream</param>
/// <param name="filename"> - Name of file to be opened</param>
/// <returns></returns>
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

/// <summary>
/// Reads an open files and parses the contents line by line to a vector
/// </summary>
/// <param name="fs"> - The file stream</param>
/// <returns>True on successful files parsing. False if file is not open</returns>
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

/// <summary>
/// Closes the open file in the stream.
/// </summary>
/// <param name="fs"> - The file stream</param>
/// <returns>True if file is closed. False if no file is open in stream</returns>
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

/// <summary>
/// Converts lines in fileContents vector to a string for display by the terminal.
/// </summary>
/// <returns>The entire contents as a string</returns>
std::string Filesystem::parseContents()
{
	std::string contents = "";
	for (const auto& line : fileContents)
	{
		contents += line + "\n";
	}

	return contents;
}
