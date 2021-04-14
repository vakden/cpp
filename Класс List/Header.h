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
	// ���������� ������ �������� � ������ ������
	void InsertLast(const char &);
	bool DeleteFirst();
	void List::DeleteLast();
	// �������� �������� �� ������ ������
	const char Top() const;
	// ���������� ������ ������� ������
	void ListPrint() const; // ������ ��������� ������
	void ListPrint(); // ������ ��������� ������
	void ForEach(void(char))const;
	// ��������� �������� ��� ����� ���������� ������, �� ������� ���
	const int Find(char&);
	const int List::FindSr(char&);
	const bool List::FindDel(char&);
	// ��������� �������� ��� ����� ���������� ������, ������� ���
	List() { First = NULL; } // �����������
	List(const List&); // ����������� �����������
	const List & operator = (const List &); // �������� ������������
	virtual~List(); // ����������
	void Erase(); // �������� ��������� ������ ������
protected:
	void Clone(const List &); // ������������
};
