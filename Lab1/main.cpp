// разбить все сложные задачи на мелкие, более простые 
#include <iostream>
#include <algorithm>
#include "Bankomat.h"
#include "Bankomat.cpp"

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
	/*unsigned g;
	cout << "Input sum of load " << endl;
	cin >> g;
	func.loadMoney(g);
	cout << "Input sum of take " << endl;
	unsigned f;
	cin >> f;
	if ((f < sumGet) && (f < sum))
	{
		func.takeMoney(f);
	}
	else
	{
		cout << " You can't get that amount of money" << endl;
	}*/
	cout << func.to_String() << endl;;
	return 0;
}


