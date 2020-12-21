#include <iostream>
#include "Bankomat.h"
#include "Bank_transition+Bank_withHistory.h"
#include "Node.h"


Node::Node(Bankomat* f)
{
	value = f;
	l, r = NULL;
}

Node::Node() {
	value = NULL;
}

Node* tree = NULL;

/*ÔÓÍÊÖÈß ÇÀÏÈÑÈ ÎÁÚÅÊÒÀ Â ÁÈÍÀÐÍÎÅ ÄÅÐÅÂÎ*/
void Node::push(Bankomat* a)
{
	if (value == NULL) {
		value = a;
		return;
	}
	if (l == NULL && r == NULL)
	{
		l = new Node(a);
		r = new Node(value);
		if (l->value > r->value)
		{
			Bankomat* buff = r->value;
			r->value = l->value;
			l->value = buff;
		}
		value = r->value;
		return;
	}
	if (l != NULL && l->value > a)
	{
		l->push(a);
	}
	else
	{
		if (r == NULL) {
			r = new Node(a);
		}
		else {
			r->push(a);
		}
	}
	if (r != NULL) {
		value = r->value;
	}
	else {
		value = l->value;
	}
}

void Node::remove(Bankomat* a)
{
	if (value == NULL) {
		return;
	}
	if (l == NULL && r == NULL) {
		if (value == a) {
			value = NULL;
		}
		return;
	}
	if (l != NULL && l->value > a)
	{
		l->remove(a);
		if (l->value == NULL) {
			l = NULL;
			if (r != NULL) {
				value = r->value;
			}
			else {
				value = NULL;
			}
		}
	}
	else if (r != NULL)
	{
		r->remove(a);
		if (r->value == NULL) {
			r = NULL;
			if (l != NULL) {
				value = l->value;
			}
			else {
				value = NULL;
			}
		}
	}
}

Bankomat* Node::find(char* id) {
	if (value == NULL) {
		return NULL;
	}
	if (*value == id) {
		std::cout << value << std::endl;
		return value;
	}
	if (l == NULL & r == NULL) {
		return NULL;
	}
	if (l != NULL && *l->value > id) {
		std::cout << l->find(id) << std::endl;
		return l->find(id);
	}
	else if (r != NULL) {
		std::cout << r->find(id) << std::endl;
		return r->find(id);
	}
}

void Node::print()
{
	if (value == NULL) return;
	if (l == NULL && r == NULL)
	{
		std::cout << *value << std::endl;
	}
	if (l != NULL) {
		l->print();
	}
	if (r != NULL) {
		r->print();
	}
}
