#pragma once
class Bankomat
{
public:
	void setId(char*);
	char* getId();
	void setSumBank(unsigned);
	unsigned getSumBank();
	void setSumMaxGet(unsigned);
	unsigned getSumMaxGet();
	void setM(int);
	int getM();
	unsigned loadMoney(unsigned);
	unsigned takeMoney(unsigned);
	char* to_String();
	Bankomat();
	Bankomat(const Bankomat& Bankomat);
	Bankomat(char* id1, unsigned sumBank1, unsigned sumMaxGet1);
	~Bankomat();
	void in();
	friend Bankomat operator-(Bankomat, unsigned);
	friend Bankomat operator+(Bankomat, unsigned);
	friend bool operator>=(Bankomat, unsigned);
	friend bool operator<(Bankomat, unsigned);
	char* operator()();
	Bankomat operator=(const Bankomat &);
	friend std::ostream& operator<<(std::ostream&,const Bankomat& );
	friend std::istream& operator>>(std::istream&, Bankomat&);
private:
	static int s_idGenerator;
	int m_id;
protected:
	char* id = new char[100];
	unsigned sumMaxGet;
	unsigned sumBank;
};



class Bank_name_address : public Bankomat
{
public: // в private char* оба, задать конструктор
	Bank_name_address(char*, char*);
	char* showName_Address();
private:
	char* bankName = new char[100];
	char* bankAddress = new char[100];
};

class Bank_transition  // Включает в себя информацию за одну транзакцию: Дата, Сумма снятия либо зачисления и остаток 
{
public:
	friend std::ostream& operator<<(std::ostream&, const Bank_transition&);
	unsigned getIncome();
	unsigned getRemain();
	bool getBool();
	time_t getTime();
	Bank_transition();
	Bank_transition(unsigned,unsigned,bool); // конструктор создания 
private:
	time_t now;
	unsigned income;
	unsigned remain;
	bool dickhead;
};

class Bank_withHistory : private Bankomat  // Массив 
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