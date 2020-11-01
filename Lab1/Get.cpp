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