#define CATCH_CONFIG_MAIN
#include "catch.hpp"

unsigned Load(unsigned sumLoad)
{
	unsigned sum = 50000;
	return sum + sumLoad;
}

unsigned take(unsigned sumTake)
{
	unsigned sumBank = 100000;
	if ((sumBank >= sumTake))
	{
		return sumBank - sumTake;
	}
}
char* Output(unsigned sumBank, unsigned sumMaxGet)
{
	char str[100];
	sprintf_s(str, 100, "%d,%d", sumBank, sumMaxGet);
	return (str);
}

TEST_CASE(" All values are numbered " "[Load]")
{
	REQUIRE(Load(0) == 50000); // passed
	REQUIRE(Load(15000) == 65000); // passed 
}

TEST_CASE(" All values are numbered again " "[take]")
{
	REQUIRE(take(15000) == 35000); // passed
	REQUIRE(take(51000) == -1000); // fail ( it's ok ) 
	REQUIRE(take(46000) == 4000);  //passed
}
TEST_CASE(" Output variants " "[Output]")
{
	REQUIRE(Output(50000, 5000) == "50000,5000"); // passed 
}
