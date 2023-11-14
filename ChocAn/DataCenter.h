#pragma once
#include "Terminal.h"
#include "Registration.h"
#include "Filesystem.h"
#include "Reports.h"

class DataCenter
{
public:
	DataCenter() {};
	~DataCenter() {};

	void start();
private:
	Terminal terminal;
	Registration registration;
	Filesystem filesystem;
	Reports reports;
};
