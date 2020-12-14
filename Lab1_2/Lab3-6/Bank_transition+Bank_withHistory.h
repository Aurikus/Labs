#pragma once
class Bank_transition  // �������� � ���� ���������� �� ���� ����������: ����, ����� ������ ���� ���������� � ������� 
{
public:
	unsigned getIncome();
	unsigned getRemain();
	bool getBool();
	time_t getTime();
	Bank_transition();
	Bank_transition(unsigned, unsigned, bool); // ����������� �������� 
	~Bank_transition();
	friend std::ostream& operator<<(std::ostream&, const Bank_transition& Bank_transition);
private:
	time_t time;
	unsigned income;
	unsigned remain;
	bool get;
};

class Bank_withHistory : private Bankomat  // ������ 
{
public:
	Bank_withHistory(char*, unsigned, unsigned);
	~Bank_withHistory();
	virtual const char* report();
	unsigned loadMoney(unsigned);
	unsigned takeMoney(unsigned);
private:
	int capacity = 0;
	int maxSize = 10;
	int flag = 0;
	Bank_transition* arr = new Bank_transition[10];
};