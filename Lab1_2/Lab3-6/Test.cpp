#include "Bankomat.h"
#include "Node.h"
#include "iostream"


void TestIntTemplate()
{
	Bi_tree<int> Int;
	int l = 50, Fi = 534, Dzhi = 75747;
	Int.push(&l);
	Int.push(&Fi);
	Int.push(&Dzhi);
	Int.toString();
}

void TestFloatTemplate()
{
	Bi_tree<float> Float;
	float Fly = 62,5, FlyAgain = 777,77;
	Float.push(&Fly);
	Float.push(&FlyAgain);
	Float.toString();
}

void TestBankomatTemplate()
{
	Bi_tree<Bankomat> Buba;
	char* Fr = new char[20];
	std::cin.getline(Fr, 20);
	char* Frisbi = new char[20];
	std::cin.getline(Frisbi, 20);
	Bankomat Free(Fr, 150, 50);
	Bankomat Frusha(Frisbi, 1505, 5034);
	Buba.push(&Free);
	Buba.push(&Frusha);
	Buba.toString();
}

void testAllValues()
{
	TestIntTemplate();
	TestFloatTemplate();
	TestBankomatTemplate();
}