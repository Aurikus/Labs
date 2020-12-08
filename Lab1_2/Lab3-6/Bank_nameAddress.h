#pragma once
class Bank_name_address : public Bankomat
{
public: // в private char* оба, задать конструктор
	Bank_name_address(char*, char*);
	char* showName_Address();
private:
	char* bankName = new char[100];
	char* bankAddress = new char[100];
};
