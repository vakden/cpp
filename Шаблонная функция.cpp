#include <iostream>
#include <vector>

using namespace std;


template <typename T>
void sort(T* arr, int size)
{
	vector<double> a;
	vector<T> b;
	for (int i = 0; i < size; i++)
	{
		int c = 0;
		for(int j = 0; j < b.size(); j++)
		{
			if (arr[i] == b[j])
				c++;
		}
		if (c == 0)
			b.push_back(arr[i]);
	}
	int i = 0;
	for (int i = 0; i < size; i++)
	{
		double num = 0;
		for(int j = 0; j < size; j++)
		{
			if (arr[i] == arr[j])
				num++;
		}
		num += 0.5;
		int j = 0;
		while(arr[i] != b[j])
		{
			j++;
			num -= 0.5/b.size();
		}
		a.push_back(num);
	}
	for (int i = 0; i < a.size() - 1; i++)
	{
		for (int j = 0; j < a.size() - 1 - i; j++)
		{
			if(a[j] < a[j+1])
			{
				swap(a[j], a[j + 1]);
				swap(arr[j],arr[j+1]);
			}
		}
	}

}

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	int* a;
	cout << "Введите количество элементов массива(int*):" << endl;
	cin >> n;
	if (n < 1)
	{
		cout << "Количество элементов массива не может быть меньше 1" << endl;
		return 0;
	}
	a = new int[n];
	cout << "Введите элементы массива(int):" << endl;
	for (int i = 0; i < n; i++)
	{
		int ch;
		cin >> ch;
		a[i] = ch;
	}
	sort(a, n);
	cout << "Отсортированный массив:" << endl;
	for(int i = 0; i < n ; i++)
	{
		cout << a[i] << endl;
	}
	double* c;
	cout << "Введите количество элементов массива(double*):" << endl;
	cin >> n;
	if (n < 1)
	{
		cout << "Количество элементов массива не может быть меньше 1" << endl;
		return 0;
	}
	c = new double[n];
	cout << "Введите элементы массива(double):" << endl;
	for (int i = 0; i < n; i++)
	{
		double ch;
		cin >> ch;
		c[i] = ch;
	}
	sort(c, n);
	cout << "Отсортированный массив:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << c[i] << endl;
	}
	char** b;
	cout << "Введите количество элементов массива(сhar*):" << endl;
	cin >> n;
	if (n < 1)
	{
		cout << "Количество элементов массива не может быть меньше 1" << endl;
		return 0;
	}
	b = new char* [n];
	for (int i = 0; i < n; i++)
	{
		b[i] = new char[30];
	}
	cout << "Введите элементы массива(char):" << endl;
	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		cin.getline(b[i], 31);
	}
	sort(b, n);
	cout << "Отсортированный массив:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << endl;
	}
	
	system("pause");
	return 0;
	
}