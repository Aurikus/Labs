#pragma once

class Node
{
public:
	Bankomat* value;
	Node* l, * r;
	Node();
	Node(Bankomat*);
	void push(Bankomat*);
	void remove(Bankomat*);
	Bankomat* find(char*);
	void print();
};