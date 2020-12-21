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
	virtual unsigned loadMoney(unsigned);
	virtual unsigned takeMoney(unsigned);
	char* to_String();
	Bankomat();
	Bankomat(const Bankomat& Bankomat);
	Bankomat(char* id1, unsigned sumBank1, unsigned sumMaxGet1);
	~Bankomat();
	friend Bankomat operator-(Bankomat, unsigned);
	friend Bankomat operator+(Bankomat, unsigned);
	bool operator>(Bankomat);
	bool operator<(Bankomat);
	bool operator==(Bankomat);
	bool operator>(char*);
	bool operator<(char*);
	bool operator==(char*);
	char* operator()();
	Bankomat operator=(const Bankomat &);
	friend std::ostream& operator<< (std::ostream&, const Bankomat &Bankomat);
	friend std::istream& operator>> (std::istream&,Bankomat &Bankomat);
private:
	static int s_idGenerator;
	int m_id;
protected:
	char* id = new char[100];
	unsigned sumMaxGet;
	unsigned sumBank;
};