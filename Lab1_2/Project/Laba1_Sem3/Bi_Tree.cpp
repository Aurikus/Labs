#include <iostream>
#include "Bankomat.h"
#include "Bank_transition+Bank_withHistory.h"


class Node
{
public:
	Bankomat* value;                          
	Node* l, * r;                        //����� � ������ ����� ������
	Node(Bankomat*);
};

Node::Node(Bankomat* f)
{
	value = f;
	l, r = NULL;
}

Node* tree = NULL;                      

/*������� ������ ������� � �������� ������*/
void push(Bankomat* a, Node** t)
{
	if ((*t) == NULL) 
	{
		(*t) = new Node(a);
		return;                         
	}
	//������ ����
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

/*������� ����������� ������ �� ������*/
void print(Node* t, int u)
{
	if (t == NULL) return;                  //���� ������ ������, �� ���������� ������, �������
	else
	{
		print(t->l, ++u);                   //� ������� ������������ �������� ����� ���������
		for (int i = 0; i < u; ++i) std::cout << "|";
		std::cout << t->info << std::endl;            //���������� �������
		u--;
	}
	print(t->r, ++u);                       //� ������� �������� �������� ������ ���������
}

int main()
{
	int n;                              //���������� ���������
	Bankomat* s;                              //������,������������ � ������
	std::cout << "������� ���������� ���������  ";
	std::cin >> n;                           //������ ���������� ���������

	for (int i = 0; i < n; ++i)
	{
		std::cout << "������� ������  ";
		std::cin >> *s;                       //��������� ������� �� ���������

		push(s, &tree);                 //� ������ ������ � ������
	}
	std::cout << "���� ������\n";
	print(tree, 0);
	std::cin.ignore().get();
}