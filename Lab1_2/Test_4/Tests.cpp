#define _CRT_SECURE_NO_WARNINGS
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "time.h"
#include <sstream>
#include <iostream>

using namespace std;

int flag = 0;
int capacity = 0;
int maxSize = 10;
int sumBank = 1999999;

class Bank_transition  
{
public:
	Bank_transition();
	Bank_transition(unsigned, unsigned, bool);
	time_t now;
	unsigned loadMoney(unsigned);
	unsigned takeMoney(unsigned);
	const char* report();
	unsigned income;
	unsigned remain;
	bool get;
	friend std::ostream& operator<<(std::ostream&, const Bank_transition&);
};

std::ostream& operator<<(std::ostream& os, const Bank_transition& p)
{ 
	char buff[20];
	strftime(buff, 20, "%d/%m/%Y:%H:%M:%S", localtime(&p.now));
	string s(buff);
	os << "Time of transition: " << s << "\nsum of taking/loading " << p.income << "\nsum of remaining: " << p.remain << endl;
	return os;
}

Bank_transition* arr = new Bank_transition[10];
Bank_transition::Bank_transition()
{
	now = time(0);
	income = 1000;
	remain = 10000;
	get = true;
}

Bank_transition::Bank_transition(unsigned income1, unsigned remain1, bool get1)
{
	now = time(0);
	income = income1;
	remain = remain1;
	get = get1;
}

unsigned Bank_transition::loadMoney(unsigned getting)
{	
	unsigned save = loadMoney(getting);
	arr[flag] = Bank_transition(getting, sumBank, true);
	flag = (flag + 1) % 10;
	if (capacity < maxSize)
	{
		capacity++;
	}
	return save;
}
unsigned Bank_transition::takeMoney(unsigned silver)
{
	unsigned save = takeMoney(silver);
	arr[flag] = Bank_transition(silver, sumBank, false);
	flag = (flag + 1) % 10;
	if (capacity < maxSize)
	{
		capacity++;
	}
	return save;
}


const char* Bank_transition::report()
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
			ss << arr[i];
		}
	}
	return ss.str().c_str();
}

int main()
{
	Bank_transition fu;
		fu.loadMoney(33333);
		fu.takeMoney(323);
		fu.takeMoney(4444);
		fu.takeMoney(15000);
		fu.loadMoney(33333);
		fu.takeMoney(323);
		fu.takeMoney(4444);
		fu.takeMoney(15000);
		fu.loadMoney(33333);
		fu.takeMoney(323);
		fu.takeMoney(4444);
		fu.report();
		return 0;
}

