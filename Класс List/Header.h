#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <assert.h>
#include <iomanip>

using namespace std;

class List {
protected:
	struct ListItem {
		char Info;
		ListItem *Next;
	};
	ListItem *First;
public:
	void InsertFirst(const char &);
	// добавление нового элемента в начало списка
	void InsertLast(const char &);
	bool DeleteFirst();
	void List::DeleteLast();
	// удаление элемента из начала списка
	const char Top() const;
	// посмотреть первый элемент списка
	void ListPrint() const; // печать элементов списка
	void ListPrint(); // печать элементов списка
	void ForEach(void(char))const;
	// выполнить действия над всеми элементами списка, не изменяя его
	const int Find(char&);
	const int List::FindSr(char&);
	const bool List::FindDel(char&);
	// выполнить действия над всеми элементами списка, изменяя его
	List() { First = NULL; } // конструктор
	List(const List&); // конструктор копирования
	const List & operator = (const List &); // оператор присваивания
	virtual~List(); // деструктор
	void Erase(); // удаление элементов списка списка
protected:
	void Clone(const List &); // клонирование
};
