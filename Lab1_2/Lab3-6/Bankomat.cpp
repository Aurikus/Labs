#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <exception>
#include "Bankomat.h"
#include "Bank_transition+Bank_withHistory.h"
#include "Bank_nameAddress.h"
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
			throw invalid_argument("Invalid arg");
		}
		if (subtract < 0)
		{
			throw invalid_argument("Invalid arg");
		}
	}
	catch (const std::invalid_argument & err)
	{
		cerr << " Invalid argument: " << err.what() << endl;
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
			throw std::invalid_argument("Invalid arg");
		}
	}
	catch (const std::invalid_argument & err)
	{
		cerr << " Invalid argument: " << err.what() << endl;
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

std::istream& operator>>(std::istream& is, Bankomat& p)
{
	is >> p.id >> p.sumBank >> p.sumMaxGet;
	return is;
}