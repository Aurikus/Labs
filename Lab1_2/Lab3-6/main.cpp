#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <stack>
#include "Bankomat.h"
#include "Bank_transition+Bank_withHistory.h"
#include "Bank_nameAddress.h"
#include "Node.h"
#include <time.h>
#include <map>

using namespace std;

void Lab8_Object_Test()
{
	int a, b;
	char* SS = new char[20];
	const char* SSS = "Happiness ";
	int start, end;
	stack <Bankomat> myStack;
	cout << " Start BaNkOmAt stack " << endl;
	start = clock();
	strcpy(SS, SSS);
	for (int g = 0; g < 10000; g++)
	{
		a = rand() % 10000;
		b = rand() % 5000;
		Bankomat* Afs = new Bankomat(SS, a, b);
		myStack.push(*Afs);
	}
	end = clock() - start;
	cout << " Time for creating : " << end << endl;
	start = clock();
	for (int i = 1; i < 3; i++)
		myStack.pop();
	end = clock() - start;
	cout << " Time for delete : " << end << endl;

	// Map

	char* SS = new char[20];
	const char* SSS = "Happiness ";
	int start, end;
	multimap<int, Bankomat> myMultiMap;
	cout << " Start bankomat multimap " << endl;
	start = clock();
	strcpy(SS, SSS);
	for (int i = 0; i < 10000; i++)
	{
		a = rand() % 10000;
		b = rand() % 5000;
		Bankomat* Afs = new Bankomat(SS, a, b);
		myMultiMap.insert(make_pair(i, Bankomat::add(i, Afs)));
	}

	end = clock() - start;
	cout << " Time for creating : " << end << endl;

	map<int, Bankomat> ::iterator it2;

	start = clock();

	it2 = myMultiMap.find(10001);

	end = clock() - start;
	cout << "Searching time: " << end << endl;

	start = clock();
	for (int i = 1; i < 10000; i++) myMultiMap.erase(i);
	end = clock() - start;
	cout << "Deleting time: " << end << endl;

}


void Lab_8()
{
	stack <int> myIntStack;
	int start, end;
	start = clock();
	cout << " Start int stack " << endl;
	for (int i = 0; i < 10000; i++)
		myIntStack.push(i);
	end = clock() - start;
	cout << " Time for creating : " << end << endl;
	start = clock();
	for (int i = 1; i < 10000; i++)
		myIntStack.pop();
	end = clock() - start;
	cout << " Time for delete : " << end << endl;

	multimap<int, int> myIntMap;

	start = clock();

	for (int i = 0; i < 10000; i++) myIntMap.insert(make_pair(i, 10000 - i)); //добавление 10000 элементов

	end = clock() - start;
	std::cout << "Creating time: " << end << endl;

	map<int, int> ::iterator it;

	start = clock();

	it = myIntMap.find(10001);

	end = clock() - start;
	std::cout << "Searching time: "<< end << endl;

	start = clock();
	for (int i = 1; i < 10000; i++) myIntMap.erase(i);
	end = clock() - start;
	std::cout << "Deleting time: " << end << endl;

}


int main()
{
	Lab8_Object_Test();
	Lab_8();
	return 0;
}