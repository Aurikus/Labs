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

int main()
{
	Bi_tree<Bankomat> Buba;
	Bi_tree<int> Int;
	Bi_tree<float> Float;
	int l = 50, Fi = 534, Dzhi = 75747;
	float Fly = 62.5, FlyAgain = 777.77;
	char* Fr = new char[20];
	cin.getline(Fr, 20);
	char* Frisbi = new char[20];
	cin.getline(Frisbi, 20);
	Bankomat Free(Fr, 150, 50);
	Bankomat Frusha(Frisbi, 1505, 5034);

	Int.push(&l);
	Int.push(&Fi);
	Int.push(&Dzhi);

	Float.push(&Fly);
	Float.push(&FlyAgain);

	Buba.push(&Free);
	Buba.push(&Frusha);
	Buba.toString();
	return 0;
}