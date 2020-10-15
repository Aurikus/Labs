#include <iostream>
#include <algorithm>
#include "head.h"
#include <string>

using namespace std;

void Bankomat::loadMoney(unsigned sumLoad) // Функция загрузки денег в Банкомат
{
	sumBank += sumLoad;
	cout << "sumBank "<< sumBank << endl;
}

void Bankomat::takeMoney(unsigned sumTake) // Cнятие определенной суммы денег
{
	if ((sumBank >= sumTake) && (sumTake <= sumMaxGet))
	{
		sumBank -= sumTake;
	}
	else
	{
		cout << "You can't get that much money. Max sum of taking  = " << min(sumBank, sumMaxGet) << endl;
	}
	cout << " Amount in Bank: " << sumBank << endl;
}

void Bankomat::show() // Строковое представление объекта
{
	cout << " ID : " << id << endl;
	cout << " Sum in Bank :" << sumBank << endl;
	cout << " Max Sum :" << sumMaxGet << endl;
}

string Bankomat::to_String()
{
	string view1 =	to_string(sumBank);
	string view2 = to_string(sumMaxGet);
	string view3(id);
	return (view1 + view2 + view3);
}

// framework catch для создания тестов 