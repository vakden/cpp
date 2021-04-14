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
	cout << "Введите количество элементов в строчке и столбце квадратного массива: ";
	cin >> x;
	if (x < 2)
	{
		cout << "Некорректно введены размеры массива" << endl;
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
	cout << "Введите вариант формирования массива: 0 - вручную, 1 - случайным образом: ";
	int sposob;
	cin >> sposob;
	
	if (sposob == 1)
	{
		int gr1, gr2, temp;
		cout << "Введите границы генерации случайных чисел массива " << endl;
		cout << "Введите первую границу: ";
		cin >> gr1;
		cout << "Введите вторую границу: ";
		cin >> gr2;
		if (gr1 > gr2)
		{
			temp = gr2;
			gr2 = gr1;
			gr1 = temp;
		}
		cout << "Ваш массив:" << endl;
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
				cout << "Введите элемент массива в " << i + 1 << " строчке " << j + 1 << " ячейке: ";
				cin >> a[i][j];
			}
		}
	}
	else
	{
		cout << "Введён несуществующий вариант формирования массива" << endl;
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
			cout << "В " << j+1 << " cтолбце есть положительные элементы" << endl;
		}
		else
		{
			cout << max << " максимальный элемент в " << j+1 << " столбце" << endl;
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

	cout << "В нижнем правом треугольнике матрицы " << sch << " отрицательных элементов" << endl;

	for (int i = 0; i < x; i++)
		delete[] a[i];
	delete[] a;

	system("pause");
}