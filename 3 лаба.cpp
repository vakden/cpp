#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
    int	srand(time(NULL));
	int c = 0, n1, gr1, gr2, temp, proizv = 1, proverka1 = 1, proverka2 = 1, sum = 0, sposob;
	int const n = 1000;
	int a1[n];
	for (int i = 0; i <= n; i++)
	{
		a1[i] = 0;
	}
	cout << "������� ���������� ��������� ������� (�� ������ 1000, �� ����� 1): ";
	cin >> n1;
	if ((n < n1) || (n1 <= 1))
	{
		cout << "����������� ������� �������� ���������� ��������� �������" << endl;
		return 0;
	}
	cout << "�������� ������ ����������� �������: 0 - �������, 1 - ��������� �������: ";
	cin >> sposob;
	if ((sposob != 1) && (sposob != 0))
	{
		cout << "������ �������� ������������ ������� ����" << endl;
		return 0;
	}
	if (sposob == 0)
	{
		for (int i = 0; i <= (n1 - 1); i++)
		{
			cout << "������� " << (i + 1) << " ������� �������: ";
			cin >> a1[i];
		}
	}
	else if (sposob = 1)
	{   
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
		for (int i = 0; i <= (n1 - 1); i++)
		{
			a1[i] = rand() % (gr2 - gr1 + 1) + gr1;
			cout << (i + 1) << " ������� ��cc��� " << a1[i] << endl;
		}
	}
	for (int i = 0; i <= (n1 - 1); i+=2)
	{
		proizv *= a1[i];
	}
	cout << "������������ ��������� ������� � ������� �������� �����: " << proizv << endl;
	int i = 0, j = (n1 - 1);
	for (; i < n1; i++)
	{
		if (a1[i] == 0)
		{
			c++;
			break;
		}
	}
	for (; j >= 0; j--)
	{
		if (a1[j] == 0)
			break;
	}
	for (int k = i; k <= j; k++)
	{
      		sum += a1[k];
	}
	if (j == i)
	{
		cout << "���������� ����� �������� ���������� ��� (����� ������� ������ ����)" << endl;
	}
	else if (c == 0)
	{
		cout << "����� ������ ���� ��� � �������" << endl;
	}
	else if (j - i == 1)
	{
		cout << "������������ ����� ������ ���� ����� � ������� �� ���������" << endl;
	}
	else if (j - i != 1)
	{
		cout << "����� ������ ������� ����� ������ � ��������� �������� ���������� �����: " << sum << endl;
	}
	c = 0;
	for (int i = 0; i < n1; i++)
	{
		if (a1[i] < 0)
		{
			temp = a1[i];
			for (int j = i; j > c; j--)
			{
				a1[j] = a1[j - 1];
			}
			a1[c] = temp;
			c++;
		}
	}
	for (int i = 0; i < n1; i++)
	{
		cout << i + 1 << " ������� ���������������� �������: " << a1[i] << endl;
	}
	system("pause");
}