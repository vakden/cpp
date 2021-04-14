//Ñïèñîê class
#include <iostream>
#include "Header.h"

using namespace std;

//******************************************************
int main()
{
	try
	{
		setlocale(LC_ALL, ".1251");
		List<char> L;
		L.ListPrint();
		L.InsertLast('a');
		L.ListPrint();
		L.InsertFirst('b');
		L.ListPrint();
		L.InsertLast('c');
		L.ListPrint();
		L.InsertLast('d');
		L.ListPrint();
		system("pause");
		return 0;
	}
	catch (char*)
	{
		cout << "ÏÓÑÒÎ!!!" << endl;
	}
}