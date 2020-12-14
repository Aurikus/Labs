#include <iostream>
#include <string>
#include "stdio.h"
#include "Bankomat.h"
#include "Bank_nameAddress.h"


using namespace std;

Bank_name_address::Bank_name_address(char* name, char* address)
{
	bankName = name;
	bankAddress = address;
}

Bank_name_address::~Bank_name_address()
{
	delete[] bankName;
	delete[] bankAddress;
}

char* Bank_name_address::showName_Address()
{
	char* str = new char[100];
	sprintf_s(str, 100, "Name = %s, Address = %s", this->bankName, this->bankAddress);
	return str;
}
