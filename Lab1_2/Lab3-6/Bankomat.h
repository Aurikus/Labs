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
	char* id = new char[100];
	unsigned sumBank;
	unsigned sumMaxGet;
	static int s_idGenerator;
	int m_id;
};