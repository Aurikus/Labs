#include "Bankomat.h"
#include "Bank_transition+Bank_withHistory.h"
#include "Bank_nameAddress.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void RunCheckAddressTest(Bank_name_address& v)
{
	cout << " Test 1: creating and checking objects " << endl;
	if (v.showName_Address() == "Name = Liliya, Address = Krupskoy")
		cout << "Test 1 passed " << endl;
	else cout << " Test 1 failed " << endl;
	cout << " Test 2: checking various objects " << endl;
	if (v.showName_Address() == "Name = Filipp1111, Address = Kirkorov ")
		cout << "Test 2 passed " << endl;
	else cout << " Test 2 failed " << endl;
	if (v.showName_Address() == "Name = SerezhaBedross, Address = Edinorosos ")
		cout << "Test 3 passed " << endl;
	else cout << " Test 3 failed " << endl;
}

void RunCheckLoadTakeMoneyTest(Bank_withHistory& v)
{
	cout << " Test 2: checking functions of class " << endl;
	cout << " Starting capital (sumBank ) = 100000 " << endl;
		v.takeMoney(10000);
		if (v.getSumBank == 90000)
			cout << " Test 1 passed " << endl;
		else
			cout << " Test 1 failed " << endl;
		v.loadMoney(15000);
		v.takeMoney(5000);
		if (v.getSumBank == 100000)
			cout << " Test 2 passed " << endl;
		else
			cout << " Test 2 failed " << endl;
		v.takeMoney(10000);
		v.loadMoney(20000);
		v.loadMoney(25000);
		if (v.getSumBank == 135000)
			cout << " Test 3 passed " << endl;
		else
			cout << " Test 3 failed " << endl;
}


void RunCheckReportTest(Bank_withHistory& g)
{
	cout << " Test 3: checking Report function " << endl;
	g.loadMoney(25000);
	g.takeMoney(10000);
	g.loadMoney(25000);
	g.report();
	cout << " If all values are right then test passed " << endl;
	g.loadMoney(12424);
	g.takeMoney(1000);
	g.loadMoney(12424);
	g.takeMoney(1000);
	g.loadMoney(12424);
	g.takeMoney(13333);
	g.loadMoney(12424);
	g.takeMoney(1000);
	g.loadMoney(12424);
	g.takeMoney(1000);
	g.loadMoney(12424);
	g.takeMoney(13333);
	g.report();
	cout << " If all values are right then test passed perfectly " << endl;
}


int main()
{
	char* name = new char[20];
	char* name2 = new char[20];
	char* address = new char[20];
	cout << " Input ID " << endl;
	cin.getline(name, 20);
	Bank_withHistory f(name,100000,50000);
	cout << " Input name " << endl;
	cin.getline(name2,20);
	cout << " Input address " << endl;
	cin.getline(address, 20);
	Bank_name_address Bee(name, address);
	// tests calls 
	RunCheckAddressTest(Bee);
	RunCheckLoadTakeMoneyTest(f);
	RunCheckReportTest(f);
	return 0;
}
