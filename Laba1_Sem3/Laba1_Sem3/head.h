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
	void loadMoney(unsigned);
	void takeMoney(unsigned);
	void show();
	std::string to_String();
	Bankomat() 
	{
		id = new char[100];
		sumBank = 100000;
		sumMaxGet = 5000;
	};
	Bankomat(char* id1, unsigned sumBank1, unsigned sumMaxGet1) 
	{
		sumBank = sumBank1;
		sumMaxGet = sumMaxGet1;
		id = id1;
	}
private:
	char* id = new char[100]; // Динамическая строка, содержащая буквы и циферки
	unsigned sumBank; // Сумма в банкомате
	unsigned sumMaxGet; // Сумма максимального снятия

};



