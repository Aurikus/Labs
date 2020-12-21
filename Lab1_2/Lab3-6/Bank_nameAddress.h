#pragma once
class Bank_name_address : private Bankomat
{
public: // в private char* оба, задать конструктор
	Bank_name_address(char*, char*);
	~Bank_name_address();
	virtual char* toString();
private:
	char* bankName = new char[100];
	char* bankAddress = new char[100];
};
