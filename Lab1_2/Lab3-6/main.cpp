#include <iostream>
#include <fstream>
#include <algorithm>
#include "Bankomat.h"

using namespace std;

int main()
{
	 // int sum, sumGet;
	char* name = new char[20];
	char* address = new char[20];
	cout << " Input ID " << endl;
	cin.getline(name, 20);
	Bank_withHistory f(name,1500050,34934);
	/* for (int i=0;i<no;i++) 
	{
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
	}*/
	/* cout << " Input name " << endl;
	cin.getline(name,20);// С++ Считает пробел за начало нового ввода,это надо пофиксить. Пока не понимаю как. 
	cout << " Input address " << endl;
	cin.getline(address, 20); */
	f.takeMoney(15000);
	f.report();
	return 0;
}
