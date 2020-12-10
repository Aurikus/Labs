#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
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
	time = time(0);
	income = 1000;
	remain = 10000;
	get = true;
}

Bank_transition::Bank_transition(unsigned income1, unsigned remain1, bool get1)
{
	time = time(0);
	income = income1;
	remain = remain1;
	get = get1;
}
~Bank_transition()
{
	delete[] time;
	delete[] income;
	delete[] remain;
}

~Bank_withHistory()
{
	delete[] arr;
	delete[] capacity;
	delete[] maxSize;
	delete[] flag;
}

unsigned Bank_withHistory::loadMoney(unsigned getting)
{
	try
	{
		if (getting < 0)
		{
			throw std::invalid_argument("Invalid arg");
		}
	}
	catch (const std::invalid_argument & err)
	{
		cerr << " Invalid argument: " << err.what() << endl;
	}
	unsigned save = Bankomat::loadMoney(getting);
	arr[flag] = Bank_transition(getting, sumBank, true);
	flag = (flag + 1) % 10;
	if (capacity < maxSize)
	{
		capacity++;
	}
	return save;
}
unsigned Bank_withHistory::takeMoney(unsigned silver)
{
	try // Try catch block works properly
	{
		if (silver < 0)
		{
			throw std::invalid_argument("Invalid arg");
		}
	}
	catch (const std::invalid_argument & err)
	{
		cerr << " Invalid argument: " << err.what() << endl;
	}
	unsigned save = Bankomat::takeMoney(silver);
	arr[flag] = Bank_transition(silver, sumBank, false);
	flag = (flag + 1) % 10;
	if (capacity < maxSize)
	{
		capacity++;
	}
	return save;
}


char* Bank_withHistory::report()
{
	std::stringstream ss;
	if (capacity == maxSize)
	{
		int index = flag;
		for (int i = 0; i < maxSize; i++)
		{
			ss << arr[index]; 
			index = (index + 1) % 10;
		}
	}
	else
	{
		int index = flag;
		for (int i = 0; i < index; i++)
		{
			ss << arr[i] << endl;
		}
	}
	return ss.str().c_str();;
}


std::ostream& operator<<(std::ostream& os, const Bank_transition& p)
{
	char buff[20];
	strftime(buff, 20, "%d/%m/%Y:%H:%M:%S", localtime(&p.time));
	string s(buff);
	os << "Time of transition: " << s << "\nsum of taking/loading " << p.income << "\nsum of remaining: " << p.remain << endl;
	return os;
}