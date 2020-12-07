#include <iostream>
#include <array>
#include <algorithm>
#include <exception>
#include "Bankomat.h"
#include <time.h>
#include <string>
#include "stdio.h"

using namespace std;

int Bankomat::s_idGenerator = 1;

Bankomat::Bankomat()
{
	m_id = s_idGenerator++;
	id = new char[100];
	sumBank = 100000;
	sumMaxGet = 5000;
};
Bankomat::Bankomat(const Bankomat& Bankomat) :
	id(Bankomat.id), sumBank(Bankomat.sumBank),sumMaxGet(Bankomat.sumMaxGet)
{
	m_id = s_idGenerator++;
}

Bankomat::Bankomat(char* id1, unsigned sumBank1, unsigned sumMaxGet1)
{
	id = id1;
	sumBank = sumBank1;
	sumMaxGet = sumMaxGet1;
	m_id = s_idGenerator++;
}
Bankomat::~Bankomat()
{
	delete[] id;
}

Bank_withHistory::Bank_withHistory(char* id1, unsigned sumBank1, unsigned sumMaxGet1)
{
	id = id1;
	sumBank = sumBank1;
	sumMaxGet = sumMaxGet1;
}
unsigned Bankomat::loadMoney(unsigned sumLoad)
{
	try // Try catch block works properly
	{
		if (sumLoad < 0)
		{
			throw std::exception();
		}
	}
	catch(const std::exception& err) 
	{
		cerr << " We caught an exception " << endl;
	}
	sumBank += sumLoad;
	return sumBank;
}

unsigned Bankomat::takeMoney(unsigned sumTake)
{
	try // Try catch block works properly
	{
		if (sumTake < 0)
		{
			throw std::exception();
		}
	}
	catch (const std::exception& err)
	{
		cerr << " We caught an exception " << endl;
	}
	if ((sumBank >= sumTake) && (sumTake <= sumMaxGet))
	{
		sumBank -= sumTake;
	}
	return sumBank;
}


Bank_name_address::Bank_name_address(char* name, char* address)
{
	bankName = name;
	bankAddress = address;
}
Bank_transition::Bank_transition()
{

	now = time(0);
	income = 1000;
	remain = 10000;
	dickhead = true;
}
Bank_transition::Bank_transition(unsigned pupa,unsigned buba ,bool dupa)
{

	now = time(0);
	income = pupa;
	remain = buba;
	dickhead = dupa;
}
char* Bank_name_address::showName_Address()
{
	char* str = new char[100];
	sprintf_s(str,100, "Name = %s, Address = %s", this->bankName, this->bankAddress);
	return str;
}

unsigned Bank_withHistory::loadMoney(unsigned posos)
{
	unsigned save = Bankomat::loadMoney(posos);
	arr[flag] = Bank_transition(posos, sumBank, true);
	flag++;
	if (capacity < maxSize)
	{
		capacity++;
	}
	return save;
}
unsigned Bank_withHistory::takeMoney(unsigned silver)
{
	unsigned save = Bankomat::takeMoney(silver);
	arr[flag] = Bank_transition(silver, sumBank, false);
	flag++;
	if (capacity < maxSize)
	{
		capacity++;
	}
	return save;
}
void Bank_withHistory::report()
{
	if (capacity == maxSize ) // capacity è size ðàçîáðàòüñÿ
	{
		int index = flag;
		for (int i = 0; i < maxSize; i++)
		{
			cout << arr[index] << endl; // TODO:ÏÅÐÅÃÐÓÇÈÒÜ ÎÏÅÐÀÒÎÐ 
			index = (index + 1) % 10;
		}
	}
	else 
	{
		int index = flag;
		for (int i = 0; i < index; i++)
		{
			cout << arr[index] << endl; // TODO:ÏÅÐÅÃÐÓÇÈÒÜ ÎÏÅÐÀÒÎÐ 
			index = (index + 1) % 10;
		}
	}
}


char* Bankomat::to_String()
{
	char* str = new char[100];
	sprintf_s(str, 100, "ID = %s, Sum in Bankomat = %d, Max sum of getting = %d", this->id, this->sumBank, this->sumMaxGet);
	return str;
}

// Operators

Bankomat operator-(Bankomat Sub, unsigned subtract) // try catch
{
	try // Try catch block works properly
	{
		if ((subtract > Sub.sumMaxGet) || (subtract > Sub.sumBank))
		{
			throw std::exception();
		}
		if (subtract < 0)
		{
			throw std::exception();
		}
	}
	catch (const std::exception & err)
	{
		cerr << " We caught an exception " << endl;
	}
	Sub.sumBank -= subtract;
	return Sub;
}

Bankomat operator+(Bankomat Sub, unsigned addition) // try catch
{
	try // Try catch block works properly
	{
		if (addition < 0)
		{
			throw std::exception();
		}
	}
	catch (const std::exception & err)
	{
		cerr << " We caught a char exception " << endl;
	}
	Sub.sumBank += addition;
	return Sub;
}

bool operator>=(Bankomat Sub, unsigned compare)
{
	return (Sub.sumBank >= compare);
}
bool operator<(Bankomat Sub, unsigned compare)
{
	return !(Sub.sumBank >= compare);
}

char* Bankomat::operator()()
{
	return (to_String());
}
Bankomat Bankomat::operator=(const Bankomat &assignment)
{
	id = assignment.id;
	sumBank = assignment.sumBank;
	sumMaxGet = assignment.sumMaxGet;
	return (*this);
}

std::ostream& operator<<(std::ostream& os,const Bankomat &p)
{ 
	os << "ID of ATM: " << p.id << "\nsum in ATM: " << p.sumBank << "\nMax sum of Get: " << p.sumMaxGet << endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Bank_transition& p)
{
	os << "Time of transition: " << p.now << "\nsum of taking/loading " << p.income << "\nsum of remaining: " << p.remain << endl;
	return os;
}

std::istream& operator>>(std::istream& is, Bankomat& p)
{
	is >> p.id >> p.sumBank >> p.sumMaxGet;
	return is;
}