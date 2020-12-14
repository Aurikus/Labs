#include <iostream>
#include "Bankomat.h"
#include "Bank_transition+Bank_withHistory.h"


class Node
{
public:
	Bankomat* value;                          
	Node* l, * r;                        //Левая и Правая часть дерева
	Node(Bankomat*);
};

Node::Node(Bankomat* f)
{
	value = f;
	l, r = NULL;
}

Node* tree = NULL;                      

/*ФУНКЦИЯ ЗАПИСИ ОБЪЕКТА В БИНАРНОЕ ДЕРЕВО*/
void push(Bankomat* a, Node** t)
{
	if ((*t) == NULL) 
	{
		(*t) = new Node(a);
		return;                         
	}
	//Дерево есть
	if ((*t)->l == NULL && (*t)->r == NULL)
	{
		(*t)->l = new Node(a);
		(*t)->r = new Node((*t)->value);
		if ((*t)->l->value > (*t)->r->value)
		{
			Bankomat* buff = (*t)->r->value;
			(*t)->r->value = (*t)->l->value;
			(*t)->l->value = buff;
		}
		(*t)->value = (*t)->r->value;
		return;
	}
	if ((*t)->l->value > a)
	{
		push(a,&(*t)->l);
	}
	else
	{
		push(a, &(*t)->r);
	}
}

/*ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ*/
void print(Node* t, int u)
{
	if (t == NULL) return;                  //Если дерево пустое, то отображать нечего, выходим
	else
	{
		print(t->l, ++u);                   //С помощью рекурсивного посещаем левое поддерево
		for (int i = 0; i < u; ++i) std::cout << "|";
		std::cout << t->info << std::endl;            //показываем элемент
		u--;
	}
	print(t->r, ++u);                       //С помощью рекурсии посещаем правое поддерево
}

int main()
{
	int n;                              //Количество элементов
	Bankomat* s;                              //Объект,передаваемый в дерево
	std::cout << "введите количество элементов  ";
	std::cin >> n;                           //Вводим количество элементов

	for (int i = 0; i < n; ++i)
	{
		std::cout << "введите объект  ";
		std::cin >> *s;                       //Считываем элемент за элементом

		push(s, &tree);                 //И каждый кладем в дерево
	}
	std::cout << "ваше дерево\n";
	print(tree, 0);
	std::cin.ignore().get();
}