#pragma once
class Bank_transition  // �������� � ���� ���������� �� ���� ����������: ����, ����� ������ ���� ���������� � ������� 
{
public:
	friend std::ostream& operator<<(std::ostream&, const Bank_transition&);
	unsigned getIncome();
	unsigned getRemain();
	bool getBool();
	time_t getTime();
	Bank_transition();
	Bank_transition(unsigned, unsigned, bool); // ����������� �������� 
private:
	time_t now;
	unsigned income;
	unsigned remain;
	bool dickhead;
};

class Bank_withHistory : private Bankomat  // ������ 
{
public:
	Bank_withHistory(char*, unsigned, unsigned);
	// Bank_transition* arr = new Bank_transition[10];
	void report();
	unsigned loadMoney(unsigned);
	unsigned takeMoney(unsigned);
private:
	int capacity = 0;
	int maxSize = 10;
	int flag = 0;
	Bank_transition* arr = new Bank_transition[10];
};