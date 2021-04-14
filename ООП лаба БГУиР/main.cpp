#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	try
	{
		setlocale(LC_ALL, ".1251");
		List L;
		L.ListPrint();
		L.InsertFirst('w');
		L.ListPrint();
		L.InsertLast('a');
		L.ListPrint();
		L.InsertFirst('b');
		L.ListPrint();
		L.InsertLast('c');
		L.ListPrint();
		L.InsertLast('d');
		L.ListPrint();
		List M(L);
		M.ListPrint();
		M.Erase();
		M.ListPrint();
		M = L;
		M.ListPrint();
		L.FindSr('b');
		L.FindSr('d');
		L.FindSr('c');
		L.Insert('k', 'a');
		L.ListPrint();
		L.FindSr('s');
		L.Iz('1');
		L.ListPrint();
		L.FindDel('1');
		L.DeleteFirst();
		L.DeleteLast();
		L.Erase();
		L.ListPrint();
		system("pause");
		return 0;
	}
	catch (char*)
	{
		cout << "осярн!!!" << endl;
	}
}