#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	try
	{
		setlocale(LC_ALL, "rus");
		BigInt s;
		cout << "������� ������ ������: ";
		cin >> s;
		cout << "��� ������: " << endl;
		cout << s << endl;;
		int a = 5;
		s = a;
		cout << "������������ ���������� ���� ���: " << endl;
		cout << s << endl;;
		BigInt t;
		t = 1;
		BigInt k;
		k = s - t;
		cout << "�������������� �������� ���� �������� ������:" << endl;
		cout << k << endl;;
		k--;
		cout << "����������� ���������:" << endl;
		cout << k << endl;
		cout << "�������� �� -= � �� ��������� ������������� �����: " << endl;
		k -= 5;
		cout << k << endl;
		BigInt r(t);
		cout << "����������� �����������: " << endl;
		cout<< r <<endl;
		k = t;
		system("pause");
		return 0;
	}
	catch(char* error)
	{
		cerr << error << endl;
	}
}