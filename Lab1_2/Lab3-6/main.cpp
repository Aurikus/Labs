#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include "Bankomat.h"
#include "Bank_transition+Bank_withHistory.h"
#include "Bank_nameAddress.h"
#include "Node.h"

using namespace std;

void TestingPolymorphismQuality(Bankomat* Check)
{
	Check->takeMoney(1340);
	if (Check->getSumBank() == 13600)
	{
		cout << "If was written, that it's a child function, then Child Function was called with Polymorphism " << endl;
	}
	else
	{
		assert(Check);
	}
	Check->loadMoney(1340);
	if (Check->getSumBank() == 15000)
	{
		cout << "If was written, that it's a child function, then Child Function was called with Polymorphism " << endl;
	}
	else
	{
		assert(Check);
	}
	Check->takeMoney(1340);
	if (Check->getSumBank() == 13600)
	{
		cout << "If was written, that it's a child function, then Child Function was called with Polymorphism " << endl;
	}
	else
	{
		assert(Check);
	}
	Check->loadMoney(1340);
	if (Check->getSumBank() == 15000)
	{
		cout << "If was written, that it's a child function, then Child Function was called with Polymorphism " << endl;
	}
	else
	{
		assert(Check);
	}

}
void TestingTreePushRemove(Bankomat* sir, Node frien, Bankomat* sir1,Bankomat* sir2)
{
	frien.push(sir);
	frien.push(sir1);
	frien.push(sir2);
	frien.remove(sir2);
	frien.print();
	cout << "  If tree was shown with 2 elements then function of removing and pushing are working correctly " << endl;
}
void TestingTreeFind(Bankomat* sir, Node frien, Bankomat* sir1, Bankomat* sir2)
{
	char* Find = new char[20];
	cin.getline(Find, 20);
	frien.push(sir);
	frien.push(sir1);
	frien.push(sir2);
	frien.find(Find);
	cout << "  If tree was shown right object with the same ID, then Find is working correctly " << endl;
}

int main()
{
	char* name = new char[20];
	char* name1 = new char[20];
	char* name2 = new char[20];
	char* name3 = new char[20];
	cout << " Input ID " << endl;
	cin.getline(name, 20);
	cout << " Input ID " << endl;
	cin.getline(name1, 20);
	cout << " Input ID " << endl;
	cin.getline(name2, 20);
	cout << " Input Finding " << endl;
	cin.getline(name3, 20);
	Bankomat sir(name,15000, 5000);
	Bankomat sir1(name1, 15000, 5000);
	Bankomat sir2(name2, 15000, 5000);
	Node frien;
	TestingPolymorphismQuality(&sir);
	TestingPolymorphismQuality(&sir1);
	TestingPolymorphismQuality(&sir2);
	TestingTreePushRemove(&sir,frien,&sir1,&sir2);
	TestingTreeFind(&sir,frien, &sir1,&sir2);
	return 0;
}
