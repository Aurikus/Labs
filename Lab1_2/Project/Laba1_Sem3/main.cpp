#include <iostream>
#include <fstream>
#include <algorithm>
#include "Bankomat.h"
#include "Bank_transition+Bank_withHistory.h"
#include "Bank_nameAddress.h"

using namespace std;

int main()
{
	char* name = new char[20];
	char* name2 = new char[20];
	char* address = new char[20];
	cout << " Input ID " << endl;
	cin.getline(name, 20);
	Bank_withHistory f(name,100000,50000); 
	/* cout << " Input name " << endl;
	cin.getline(name2,20);
	cout << " Input address " << endl;
	cin.getline(address, 20);
	Bank_name_address Bee(name2, address);
	Bee.showName_Address(); */
	return 0;
}
