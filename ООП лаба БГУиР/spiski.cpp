#pragma once
#include "Header.h"
#include <iostream>

using namespace std;



void List::InsertFirst(const char &AInfo)
{
	ListItem *P = new ListItem;
	P->Info = AInfo;
	P->Next = First;
	First = P;
}

void List::InsertLast(const char &AInfo)
{
	ListItem *P = new ListItem;
	P->Info = AInfo;
	P->Next = NULL;
	ListItem *T = new ListItem;
	T = First;
	if (T == NULL)
	{
		P = First;
	}
	if (T == NULL)
	{
		P = First;
	}
	while (T != NULL)
	{
		if (T->Next != NULL)
		{
			T = T->Next;
		}
		else break;
	}
	if (T != NULL)
	{
		T->Next = P;
	}
}
bool List::Insert(char AInfo, char Find)
{
	ListItem *P = new ListItem;
	P->Next = First;
	int a = List::FindSr(Find);
	if(0 == a)
	{
		cout << "Элемента,после которого нужно вставить, в списке нету." << endl;
		return 0;
	}
	for (int i = 0; i < a; i++)
	{
		P = P->Next;
	}
	ListItem *T = new ListItem;
	T->Info = AInfo;
	T->Next = P->Next;
	P->Next = T;
	return 1;
}
bool List::DeleteFirst()
{
	if (First == NULL)
		return false; // Список пустой
	ListItem *P = First;
	First = First->Next;
	delete P;
	return true;
}
void List::DeleteLast()
{
	ListItem *T = new ListItem;
	T = First;
	while (T != NULL)
	{
		if (T->Next != NULL)
		{
			T = T->Next;
		}
		else break;
	}
	delete[] T;
}

const char List::Top() const
{
	if (First == NULL)
		throw "Список пустой";
	char x = First->Info;
	return x;
}

void List::Clone(const List &L)
{
	ListItem *p, *q, *r;
	r = NULL;
	p = L.First;
	while (p != NULL)
	{
		q = new ListItem;
		q->Info = p->Info;
		q->Next = NULL;
		if (r == NULL)
			First = q;
		else
			r->Next = q;
		r = q;
		p = p->Next;
	}
}
const int List::Find(char a)
{
	int num = 0;
	ListItem *T = new ListItem;
	T = First;
	while (T != NULL)
	{
		num++;
		if (T->Info != a)
		{
			T = T->Next;
		}
		else
		{
			cout << "Элемент с таким значением в списке находится на " << num << " месте" << endl;
			return num;
		}
	}
	if (T == NULL)
	{
		cout << "Такого элемента не обнаружено" << endl;
		return 0;
	}
}
const int List::FindSr(char a)
{
	int num = 0;
	int sr = 0;
	ListItem *T = new ListItem;
	T = First;
	while (T != NULL)
	{
		num++;
		if (T->Info != a)
		{
			T = T->Next;
			sr++;
		}
		else
		{
			cout << "Элемент с таким значением в списке находится на " << num << " месте. Найдено через " << sr << " cравнений." << endl;
			return num;
		}
	}
	if (T == NULL)
	{
		cout << "Такого элемента не обнаружено" << endl;
		return 0;
	}
}
const bool List::FindDel(char a)
{
	ListItem *T = new ListItem;
	T = First;
	while (T != NULL)
	{
		if (T->Info != a)
		{
			T = T->Next;
		}
		else
		{
			delete[] T;
			cout << "Элемент удалён" << endl;
			return 1;
		}
	}
	if (T == NULL)
	{
		cout << "Такого элемента не обнаружено" << endl;
		return 0;
	}
}
void List::Erase()
{
	ListItem *p, *q;
	p = First;
	while (p != NULL)
	{
		q = p->Next;
		delete p;
		p = q;
	}
	First = NULL;
}

List::List(const List& L)
{
	Clone(L);
}

const List & List::operator = (const List &L)
{
	if (&L == this)
		return *this; // проверка на самоприсваивание
	Erase();
	Clone(L);
	return *this;
}
List::~List()
{
	Erase();
}

void List::ListPrint()const
{
	ListItem *P = First;
	if (P == NULL)
		cout << "список пуст" << endl;
	if (P != NULL)
	{
		cout << "содержимое списка" << endl;
		while (P != NULL)
		{
			cout << P->Info << endl;
			P = P->Next;
		}
	};
}
void List::ListPrint()
{
	ListItem *P = First;
	if (P == NULL)
		cout << "список пуст" << endl;
	if (P != NULL)
	{
		cout << "содержимое списка" << endl;
		while (P != NULL)
		{
			cout << P->Info << endl;
			P = P->Next;
		}
	};
}

void Print(char x)
{
	cout << x << endl;
}
void List::Iz(char AInfo)
{
	ListItem *P = new ListItem;
	P->Next = First;
	while (P->Next != NULL)
	{
		P = P->Next;
		P->Info = AInfo;
	}
}
void List::ForEach(void Fun(char))const
{
	ListItem *P = First;
	if (P == NULL)
		cout << "список пуст" << endl;
	if (P != NULL)
	{
		cout << "содержимое списка" << endl;
		while (P != NULL)
		{
			Fun(P->Info);
			P = P->Next;
		}
	};
}