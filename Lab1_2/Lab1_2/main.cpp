#include <iostream>
#include <algorithm>
#include "Bankomat.h"

using namespace std;

int main()
{
	int sum, sumGet;
	char* n = new char[20];
	cout << " Input ID " << endl;
	cin.getline(n, 20);
	while (1)
	{
		cout << "Input sum of money " << endl;
		cin >> sum;
		if (sum > 0) break;
		else cout << "Input valid sum of money " << endl;
	}
	while (1)
	{
		cout << "Input max sum of Get" << endl;
		cin >> sumGet;
		if (sumGet > 0) break;
		else cout << "Input valid max sum of Get" << endl;
	}
	Bankomat func(n, sum, sumGet);
	unsigned g;
	cout << "Input sum of load " << endl;
	cin >> g;
	func.loadMoney(g);
	/* cout << "Input sum of take " << endl;
	unsigned f;
	cin >> f;
	if ((f < sumGet) && (f < sum))
	{
		func.takeMoney(f);
	}
	else
	{
		cout << " You can't get that amount of money" << endl;
	}
	Bankomat Sub(n, sum, sumGet);

	// ЗОНА ТЕСТИРОВАНИЯ ОПЕРАТОРОВ ПЕРЕГРУЗКИ 
	
	Sub = Sub + 15000;	// passed and worked  
	Sub = Sub - 1111;	// passed and worked 
	Bankomat GigiZaShagi = Sub; // passed and worked 
	cout << GigiZaShagi.to_String() << endl;	// passed and worked
	if (Sub >= 55000)	// passed and worked
	{
		cout << " Sum Super  :) " << endl;
	}
	else
	{
		cout << " Sum ne Super :( " << endl;
	}*/
	return 0;
}
