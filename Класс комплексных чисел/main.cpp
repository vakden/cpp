#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
	try
	{
		setlocale(LC_ALL, "rus");
		Complex value1(5, 2);
		Complex value2(3, -3);
		/*cout << "��� �����" << endl;
		cout << value1 << " " << value2 << endl;
		cout << "�����" << endl;
		cout << value1 + value2 << endl;
		cout << "��������" << endl;
		cout << value1 - value2 << endl;
		cout << "������������" << endl;
		cout << value1 * value2 << endl;
		cout << "�������" << endl;
		cout << value1 / value2 << endl;

		value1 = value2;
		cout << "������ ���������� �������" << endl;
		cout << value1 << " = " << value2 << endl;
		Complex value3;
		Complex value4;
		cout << "������� �����" << endl;
		cin >> value3;
		cin >> value4;
		if (value3 == value4)
		{
			cout << "�� ����� ������ �����" << endl;
		}
		if (value3 != value4)
		{
			cout << "�� ����� �� ������ �����" << endl;
		}*/
		Complex z;
		z = (value1 + value2) / (value1 + value1);
		cout << z << endl;
	}
	catch (const char* ex)
	{
		printf("%s\n", ex);
	}
	system("pause");
	return 0;
}