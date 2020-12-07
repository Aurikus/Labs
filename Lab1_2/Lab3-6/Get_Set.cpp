#include <iostream>
#include "Bankomat.h"

using namespace std;

void Bankomat::setId(char* id1)
{
	id = id1;
}
char* Bankomat::getId()
{
	return id;
}
void Bankomat::setSumBank(unsigned sumBank1)
{
	sumBank = sumBank1;
}
unsigned Bankomat::getSumBank()
{
	return sumBank;
}
void Bankomat::setSumMaxGet(unsigned sumMaxGet1)
{
	sumMaxGet = sumMaxGet1;
}
unsigned Bankomat::getSumMaxGet()
{
	return sumMaxGet;
}

void Bankomat::setM(int m_id1)
{
	m_id = m_id1;
}

int Bankomat::getM()
{
	return m_id;
}
unsigned Bank_transition::getIncome()
{
	return income;
}
unsigned Bank_transition::getRemain()
{
	return remain;
}

bool Bank_transition::getBool()
{
	return dickhead;
}

time_t Bank_transition::getTime()
{
	return now;
}

