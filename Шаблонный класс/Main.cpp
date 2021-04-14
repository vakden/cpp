#include "Header.h"
#include <iostream>

using namespace std;

template <typename TInfo>
void Print(TInfo &x)
{
	cout << x << "   ";
}

template <typename TInfo>
void Change(TInfo &x)
{
	x += 1;
}

template<>
void Change(char* &x)
{
	char* str = new char[strlen(x) + strlen("addedstring") + 1];
	strcpy(str, x);
	strcat(str, "addedstring");
	delete[] x;
	x = new char[strlen(str) + 1];
	strcpy(x, str);
	delete[] str;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	TDeque<int> A, B;
	TDeque<char*> C, D;
	int sw = -1, b = -1;
	bool exite = true;
	cout << "Введите: 1) для int" << endl;
	cout << "         2) для char*\n::";
	cin >> b;
	cout << "1) - insFront\n";
	cout << "2) - insRear\n";
	cout << "3) - delFront\n";
	cout << "4) - delRear\n";
	cout << "5) - getByIndex\n";
	cout << "6) - setByIndex\n";
	cout << "7) - brows с изменением\n";
	cout << "8) - brows без изменения\n";
	cout << "9) - оператор присваивания\n";
	cout << "10) - конструктор копирования\n";
	cout << "0) - для выхода\n";
	if (b == 1)
	{
		while (exite)
		{
			cout << "\n::";
			cin >> sw;
			try
			{

				switch (sw)
				{
				case 1:
				{
					cout << "Введите элемент:  ";
					int k;
					cin >> k;
					A.insFront(k);
					cout << "Deque:\n";
					A.browse(Print);
					cout << endl;
					break;
				}
				case 2:
				{
					cout << "Введите элемент:  ";
					int k;
					cin >> k;
					A.insRear(k);
					cout << "Deque:\n";
					A.browse(Print);
					cout << endl;
					break;
				}
				case 3:
				{
					int l;
					if (A.delFront(l))
						cout << "Удаленный элемент:  " << l << endl;
					else
						cout << "Дек пустой" << endl;
					cout << "Deque:\n";
					A.browse(Print);
					cout << endl;
					break;
				}
				case 4:
				{
					int l;
					if (A.delRear(l))
						cout << "Удаленный элемент:  " << l << endl;
					else
						cout << "Дек пустой" << endl;
					cout << "Deque:\n";
					A.browse(Print);
					cout << endl;
					break;
				}
				case 5:
				{
					cout << "Введите индекс:  ";
					int k;
					cin >> k;
					cout << "Элемент:  " << A.getByIndex(k) << endl;
					cout << "Deque:\n";
					A.browse(Print);
					cout << endl;
					break;
				}
				case 6:
				{
					cout << "Введите индекс:  ";
					int k;
					cin >> k;
					cout << "Введите элемент:  ";
					int s;
					cin >> s;
					A.setByIndex(s, k);
					cout << "Deque:\n";
					A.browse(Print);
					cout << endl;
					break;
				}
				case 7:
				{
					A.browse(Change);
					cout << "Deque:\n";
					A.browse(Print);
					cout << endl;
					break;
				}
				case 8:
				{
					cout << "Deque:\n";
					A.browse(Print);
					cout << endl;
					break;
				}
				case 9:
				{
					cout << "New Deque:\n";
					B = A;
					B.browse(Print);
					cout << endl;
					break;
				}
				case 10:
				{
					cout << "New Deque:\n";
					TDeque<int> b(A);
					b.browse(Print);
					cout << endl;
					break;
				}
				case 0:
				{
					exite = false;
					break;
				}
				}
			}
			catch (char* c)
			{
				cout << c << endl;
			}
		}
	}
	exite = true;
	if (b == 2)
	{
		while (exite)
		{
			cout << "\n::";
			cin >> sw;
			try
			{
				switch (sw)
				{
				case 1:
				{
					cout << "Введите элемент:  ";
					char* c = new char[20];
					cin >> c;
					C.insFront(c);
					cout << "Deque:\n";
					C.browse(Print);
					cout << endl;
					delete[] c;
					break;
				}
				case 2:
				{
					cout << "Введите элемент:  ";
					char* c = new char[20];
					cin >> c;
					C.insRear(c);
					cout << "Deque:\n";
					C.browse(Print);
					cout << endl;
					break;
				}
				case 3:
				{
					char* c = new char[20];
					if (C.delFront(c))
						cout << "Удаленный элемент:  " << c << endl;
					else
						cout << "Дек пустой" << endl;
					cout << "Deque:\n";
					C.browse(Print);
					cout << endl;
					break;
				}
				case 4:
				{
					char* c = new char[20];
					if (C.delRear(c))
						cout << "Удаленный элемент:  " << c << endl;
					else
						cout << "Дек пустой" << endl;
					cout << "Deque:\n";
					C.browse(Print);
					cout << endl;
					break;
				}
				case 5:
				{
					cout << "Введите индекс:  ";
					int k;
					cin >> k;
					cout << "Элемент:  " << C.getByIndex(k) << endl;
					cout << "Deque:\n";
					C.browse(Print);
					cout << endl;
					break;
				}
				case 6:
				{
					cout << "Введите индекс:  ";
					int k;
					cin >> k;
					cout << "Введите элемент:  ";
					char* c = new char[20];
					cin >> c;
					C.setByIndex(c, k);
					cout << "Deque:\n";
					C.browse(Print);
					cout << endl;
					break;
				}
				case 7:
				{
					C.browse(Change);
					cout << "Deque:\n";
					C.browse(Print);
					cout << endl;
					break;
				}
				case 8:
				{
					cout << "Deque:\n";
					C.browse(Print);
					cout << endl;
					break;
				}
				case 9:
				{
					D = C;
					cout << "New Deque:\n";
					D.browse(Print);
					cout << endl;
					break;

				}
				case 10:
				{
					cout << "New Deque:\n";
					TDeque<char*> v(C);
					v.browse(Print);
					cout << endl;
					break;
				}
				case 0:
				{
					exite = false;
					break;
				}
				}
			}
			catch (char* c)
			{
				cout << c << endl;
			}
		}
	}
	system("pause");
	return 0;
}