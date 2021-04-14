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
		/*cout << "Два числа" << endl;
		cout << value1 << " " << value2 << endl;
		cout << "Сумма" << endl;
		cout << value1 + value2 << endl;
		cout << "Разность" << endl;
		cout << value1 - value2 << endl;
		cout << "Произведение" << endl;
		cout << value1 * value2 << endl;
		cout << "Частное" << endl;
		cout << value1 / value2 << endl;

		value1 = value2;
		cout << "Первое приравнять второму" << endl;
		cout << value1 << " = " << value2 << endl;
		Complex value3;
		Complex value4;
		cout << "Введите числа" << endl;
		cin >> value3;
		cin >> value4;
		if (value3 == value4)
		{
			cout << "Вы ввели равные числа" << endl;
		}
		if (value3 != value4)
		{
			cout << "Вы ввели не равные числа" << endl;
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