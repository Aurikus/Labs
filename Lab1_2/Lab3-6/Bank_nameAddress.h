#pragma once
class Bank_name_address : public Bankomat
{
public: // � private char* ���, ������ �����������
	Bank_name_address(char*, char*);
	char* showName_Address();
private:
	char* bankName = new char[100];
	char* bankAddress = new char[100];
};
