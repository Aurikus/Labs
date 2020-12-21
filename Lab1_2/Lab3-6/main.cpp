#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include "Bankomat.h"
#include "Bank_transition+Bank_withHistory.h"
#include "Bank_nameAddress.h"
#include "Node.h"

using namespace std;

void TestingPolymorphismQuality(Bi_tree Check2)
{
	char* namee = new char[20];

	char* namee1 = new char[20];
	const char* m = " 123asd,15000,5000";
	cin.getline(namee,20);
	cin.getline(namee1, 20);
	Bank_withHistory bla(namee1, 15000, 5000);
	Bankomat address(namee,15000,5000);
	if ((address.toString() == m) && (Check2.toString() == m) && (bla.toString() == m ))
	{
		cout << " Polymorphism working properly " << endl;
	}
	else
	{
		cout << "Polymorphism is suck " << endl;
		assert(&Check2);
	}
}
void TestingTreePushRemove(Bankomat* sir, Bi_tree frien, Bankomat* sir1,Bankomat* sir2)
{
	frien.push(sir);
	frien.push(sir1);
	frien.push(sir2);
	frien.remove(sir2);
	frien.toString();
	cout << "  If tree was shown with 2 elements then function of removing and pushing are working correctly " << endl;
}
void TestingTreeFind(Bankomat* sir, Bi_tree frien, Bankomat* sir1, Bankomat* sir2)
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
	Bank_withHistory bla(name3, 13434, 340);
	Bi_tree frien;
	TestingPolymorphismQuality(frien);
	TestingTreePushRemove(&sir,frien,&sir1,&sir2);
	TestingTreeFind(&sir,frien, &sir1,&sir2);
	return 0;
}
