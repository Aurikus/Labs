#include <iostream>
#include "Bankomat.h"
#include "Bank_transition+Bank_withHistory.h"
#include "Node.h"

template <class T> Bi_tree<T>::Bi_tree(T* f)
{
	value = f;
	l, r = NULL;
}


template <class T> Bi_tree<T>::Bi_tree()
{
	value = NULL;
}

/*тсмйжхъ гюохях назейрю б ахмюпмне депебн*/
template <class T>
void Bi_tree<T>::push(T* a)
{
	if (value == NULL) {
		value = a;
		return;
	}
	if (l == NULL && r == NULL)
	{
		l = new Bi_tree(a);
		r = new Bi_tree(value);
		if (l->value > r->value)
		{
			T* buff = r->value;
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
			r = new Bi_tree(a);
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

template <class T>
void Bi_tree<T>::remove(T* a)
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

template<class T> T* Bi_tree<T>::find(T* id) {
	if (value == NULL) {
		return NULL;
	}
	if (*value == id) {
		std::cout <<  value <<  std::endl;
		return value;
	}
	if (l == NULL & r == NULL) {
		return NULL;
	}
	if (l != NULL && *l->value > id) {
		std::cout <<  l->find(id) <<  std::endl;
		return l->find(id);
	}
	else if (r != NULL) {
		std::cout << r->find(id) << std::endl;
		return r->find(id);
	}
}
template <class T>
char* Bi_tree<T>::toString()
{
	if (value == NULL) return 0;
	if (l == NULL && r == NULL)
	{
		std::cout << * value << std::endl;
	}
	if (l != NULL) {
		l->toString();
	}
	if (r != NULL) {
		r->toString();
	}
	return 0;
}