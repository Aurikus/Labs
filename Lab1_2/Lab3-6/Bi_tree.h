#pragma once

class Bi_tree
{
public:
	Bi_tree();
	Bi_tree(Bankomat*);
	void push(Bankomat*);
	void remove(Bankomat*);
	Bankomat* find(char*);
	virtual char* toString();
private:
	Bi_tree* l, * r;
	Bankomat* value;
};