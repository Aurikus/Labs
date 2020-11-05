#include <iostream>
#include <algorithm>
#include "Bankomat.h"
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
	sumBank = sumBank1;
	sumMaxGet = sumMaxGet1;
	id = id1;
	m_id = s_idGenerator++;
}
Bankomat::~Bankomat()
{
	delete[] id;
	delete[] &sumBank;
	delete[] &sumMaxGet;
}

unsigned Bankomat::loadMoney(unsigned sumLoad) 
{
	sumBank += sumLoad;
	return sumBank;
}

unsigned Bankomat::takeMoney(unsigned sumTake)
{
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
	Sub.sumBank -= subtract;
	return Sub;
}

Bankomat operator+(Bankomat Sub, unsigned addition) // try catch
{
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

Bankomat Bankomat::operator=(const Bankomat assignment)
{
	id = assignment.id;
	sumBank = assignment.sumBank;
	sumMaxGet = assignment.sumMaxGet;
	return (*this);
}