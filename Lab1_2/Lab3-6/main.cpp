#include <iostream>
#include <fstream>
#include <algorithm>
#include "Bankomat.h"

using namespace std;

int main()
{
	 // int sum, sumGet;
	// char* n = new char[20];
	const int f = 2;
	Bankomat Jija[f];
	for (int i = 0; i < f; i++)	
	{Jija[i].in();	}
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

	// Проверка записи в текстовый файл 
	ofstream fout("text.txt", ios::out);
		if (!fout)
		{
			cerr << "Error:unable to write to text.txt" << endl;
			exit(1);
		}
		for (int i = 0; i < f; i++)
		{
			fout << Jija[i];
		}
		fout.close();
		ifstream f1("text.txt", ios::in);
		if (!f1)
		{
			cerr << "Can't open this file " << endl;
			exit(1);
		}
		for (int i = 0; i < f; i++)
		{
			f1 >> Jija[i];
		}
	// Проверка записи в бинарный файл 
	ofstream dat_file("Bankomat.dat", ios::binary);
		if (!dat_file)
		{
			cerr << "Error:unable to write to dat file" << endl;
			exit(1);
		}
		for (int i = 0; i < f; i++)
		{
			dat_file.write((char*)&Jija[i], sizeof(Jija[i]));
		}
		ifstream dat_file1("Bankomat.dat", ios::binary);
		if (!dat_file1)
		{
			cerr << "Error: unable to read from dat file " << endl;
			exit(1);
		}
		for (int i = 0; i < f; i++)
		{
			dat_file1.read((char*) &Jija[i], sizeof(Jija[i]));
		}
	return 0;
}
