#include<iostream>
using namespace std;

void main()
{
	int n, k, p;
	setlocale(LC_ALL, "RUS");
	cout << "���� " << endl;
	cin >> n;
	for (int i = 1; n != 0; i++)
	{
		cout << "����� ���� " << endl;
		cin >> p;
		n -= p;
		cout << "� ���� �������� ";
		cout << n << endl;

		if ((n == 1) || (n == 2) || (n == 3)) 
		{
			cout << "�������� " << endl;
			break;
		}
		if (n == 0) cout << "������� " << endl;
		if (n>3)
		{   
			if (n == 5) k = 1;
			if (n == 6) k = 2;
			if (n == 7) k = 3;
			if (n>7) k = rand() % 3 + 1;
			
			cout << "��������� ���� ";
			cout << k << endl;
			n -= k;
			cout << "� ���� �������� ";
			cout << n << endl;
		}
    }



	system("pause");
}