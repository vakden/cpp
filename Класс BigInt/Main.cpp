#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	try
	{
		setlocale(LC_ALL, "rus");
		BigInt s;
		cout << "Введите объект класса: ";
		cin >> s;
		cout << "Ваш обЪект: " << endl;
		cout << s << endl;;
		int a = 5;
		s = a;
		cout << "Присваивание переменной типа инт: " << endl;
		cout << s << endl;;
		BigInt t;
		t = 1;
		BigInt k;
		k = s - t;
		cout << "Приравниваание разности двух объектов класса:" << endl;
		cout << k << endl;;
		k--;
		cout << "Постфиксный декремент:" << endl;
		cout << k << endl;
		cout << "Проверка на -= и на получение отрицательных чисел: " << endl;
		k -= 5;
		cout << k << endl;
		BigInt r(t);
		cout << "Конструктор копирования: " << endl;
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