#pragma once

template<class T>
class Bi_tree
{
public:
	Bi_tree();
	Bi_tree(T*);
	void push(T*);
	void remove(T*);
	T* find(T*);
	virtual char* toString();
private:
	Bi_tree* l, * r;
	Bankomat* value;
};