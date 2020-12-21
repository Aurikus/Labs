#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include "Bankomat.h"
#include "Bank_transition+Bank_withHistory.h"
#include "Bank_nameAddress.h"
#include "Node.h"

using namespace std;

void TestingPolymorphismQuality(Bankomat* Check, Bank_withHistory* Check1, Bi_tree Check2)
{
	Check->toString();
	Check1->toString();
	Check2.toString();
	if (Check->toString() == Check2.toString())
		cout << " All is working right " << endl;
	else
	{
		cout << " All is bad " << endl;
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
	TestingPolymorphismQuality(&sir, &bla);
	TestingPolymorphismQuality(&sir1,&bla);
	TestingPolymorphismQuality(&sir2,&bla);
	TestingTreePushRemove(&sir,frien,&sir1,&sir2);
	TestingTreeFind(&sir,frien, &sir1,&sir2);
	return 0;
}
