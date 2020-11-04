#pragma once
class Bankomat
{
public:
	void setId(char*);
	char* getId();
	void setSumBank(unsigned);
	unsigned getSumBank();
	void setSumMaxGet(unsigned);
	unsigned getSumMaxGet();
	unsigned loadMoney(unsigned);
	unsigned takeMoney(unsigned);
	char* to_String();
	Bankomat();
	Bankomat(char* id1, unsigned sumBank1, unsigned sumMaxGet1);
	friend Bankomat operator-(Bankomat, unsigned);
	friend Bankomat operator+(Bankomat, unsigned);
	friend bool operator>=(Bankomat, unsigned);
	friend bool operator<(Bankomat, unsigned);
	char* operator()();
	Bankomat operator=(const Bankomat);
private:
	char* id = new char[100];
	unsigned sumBank;
	unsigned sumMaxGet;
};



