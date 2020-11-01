#include <iostream>
#include <algorithm>
#include "Bankomat.h"
#include <string>
#include "stdio.h"

using namespace std;

Bankomat::Bankomat()
{
	id = new char[100];
	sumBank = 100000;
	sumMaxGet = 5000;
};
Bankomat::Bankomat(char* id1, unsigned sumBank1, unsigned sumMaxGet1)
{
	sumBank = sumBank1;
	sumMaxGet = sumMaxGet1;
	id = id1;
}

unsigned Bankomat::loadMoney(unsigned sumLoad) // ������� �������� ����� � ��������
{
	sumBank += sumLoad;
	return sumBank;
}

unsigned Bankomat::takeMoney(unsigned sumTake) // C����� ������������ ����� �����
{
	if ((sumBank >= sumTake) && (sumTake <= sumMaxGet))
	{
		sumBank -= sumTake;
	}
	return sumBank;
}


char* Bankomat::to_String()
{
	char str[100] = "";
	sprintf_s(str, "ID = %s, Sum in Bankomat = %d, Max sum of getting = %d", id, sumBank, sumMaxGet);
	return (str);
}
// ���������� ����������
/*
unsigned operator-(Bankomat Sub,unsigned subtract) // try catch ��������, ���������, ���� ��� ������ �� �
{
	Sub.sumBank -= subtract;
	try
	{
		throw Sub.sumBank < 0;
	}
	catch (unsigned)
	{
		cerr << " We caught an exception " << '\n';
	}
	return Sub.sumBank;
}

unsigned operator+(Bankomat Sub,unsigned addition) // try catch ��������, ���������, ���� ��� ������ �� �
{
	Sub.sumBank += addition;
	return 0;
}

bool operator>=(Bankomat Sub,unsigned compare)
{
	return (Sub.sumBank >= compare);
}
bool operator<(Bankomat Sub,unsigned compare)
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
}*/
// framework catch ��� �������� ������ 