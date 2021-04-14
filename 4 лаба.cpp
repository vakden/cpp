#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int **a;
	int x, y;
	cout << "������� ���������� ��������� � ������� � ������� ����������� �������: ";
	cin >> x;
	if (x < 2)
	{
		cout << "����������� ������� ������� �������" << endl;
		system("pause");
		return 0;
	}
	y = x;
	a = new int*[x];
	for (int i = 0; i < x; i++)
	{
		a[i] = new int[y];
	}
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			a[i][j] = 0;
		}
	}
	cout << "������� ������� ������������ �������: 0 - �������, 1 - ��������� �������: ";
	int sposob;
	cin >> sposob;
	
	if (sposob == 1)
	{
		int gr1, gr2, temp;
		cout << "������� ������� ��������� ��������� ����� ������� " << endl;
		cout << "������� ������ �������: ";
		cin >> gr1;
		cout << "������� ������ �������: ";
		cin >> gr2;
		if (gr1 > gr2)
		{
			temp = gr2;
			gr2 = gr1;
			gr1 = temp;
		}
		cout << "��� ������:" << endl;
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				a[i][j] = rand() % (gr2 - gr1 + 1) + gr1;
				cout << setw(5) << a[i][j];
				if (j == x - 1) cout << endl;
			}
		}
	
	}
	else if (sposob == 0)
	{
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				cout << "������� ������� ������� � " << i + 1 << " ������� " << j + 1 << " ������: ";
				cin >> a[i][j];
			}
		}
	}
	else
	{
		cout << "����� �������������� ������� ������������ �������" << endl;
		system("pause");
		return 0;
	}
	
	cout << endl;

	int max = 0;
	for (int j = 0; j < y; j++)
	{
		for (int i = 0; i < x; i++)
		{
			if (a[i][j] < 0)
			{
				if (i == 1)
				{
					max = a[i][j];
				}
				else if (a[i][j] > max)
					max = a[i][j];
			}
			else max = 0;
		}
		if (max == 0)
		{
			cout << "� " << j+1 << " c������ ���� ������������� ��������" << endl;
		}
		else
		{
			cout << max << " ������������ ������� � " << j+1 << " �������" << endl;
		}

	}
	cout << endl;
	int sch = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = x - 1; j >= x - i - 1; j--)
		{
			if (a[i][j] < 0) sch++;
		}
	}

	cout << "� ������ ������ ������������ ������� " << sch << " ������������� ���������" << endl;

	for (int i = 0; i < x; i++)
		delete[] a[i];
	delete[] a;

	system("pause");
}