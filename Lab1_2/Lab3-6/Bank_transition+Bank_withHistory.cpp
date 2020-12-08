#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <exception>
#include "Bank_transition+Bank_withHistory.h"
#include <time.h>
#include "stdio.h"


Bank_withHistory::Bank_withHistory(char* id1, unsigned sumBank1, unsigned sumMaxGet1)
{
	id = id1;
	sumBank = sumBank1;
	sumMaxGet = sumMaxGet1;
}


Bank_transition::Bank_transition()
{

	now = time(0);
	income = 1000;
	remain = 10000;
	dickhead = true;
}
Bank_transition::Bank_transition(unsigned pupa, unsigned buba, bool dupa)
{
	now = time(0);
	income = pupa;
	remain = buba;
	dickhead = dupa;
}

unsigned Bank_withHistory::loadMoney(unsigned posos)
{
	unsigned save = Bankomat::loadMoney(posos);
	arr[flag] = Bank_transition(posos, sumBank, true);
	flag = (flag + 1) % 10;
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
	flag = (flag + 1) % 10;
	if (capacity < maxSize)
	{
		capacity++;
	}
	return save;
}
void Bank_withHistory::report()
{
	if (capacity == maxSize) // capacity è size ðàçîáðàòüñÿ
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
			cout << arr[i] << endl; // TODO:ÏÅÐÅÃÐÓÇÈÒÜ ÎÏÅÐÀÒÎÐ 
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Bank_transition& p)
{
	char buff[20];
	strftime(buff, 20, "%d/%m/%Y:%H:%M:%S", localtime(&p.now));
	string s(buff);
	os << "Time of transition: " << s << "\nsum of taking/loading " << p.income << "\nsum of remaining: " << p.remain << endl;
	return os;
}

