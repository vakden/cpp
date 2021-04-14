#include <iostream>
#include "queue.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	LQueue a1;
	AQueue b1;
	a1.Push(1);
	a1.Push(2);
	a1.Push(3);
	cout << "Очередь на списках:" << endl;
	for(int i = 0; i < a1.GetSize(); i++)
	{
		cout << a1[i] << endl;
	}
	b1.Push(33);
	b1.Push(44);
	b1.Push(55);
	cout << "Очередь на массивах:" << endl;
	for(int i = 0; i < b1.GetSize(); i++)
	{
		cout << b1[i] << endl;
	}
	AQueue b2 = b1;
	cout << "Конструктор копирования:" << endl;
	for (int i = 0; i < b2.GetSize(); i++)
	{
		cout << b2[i] << endl;
	}
	AQueue b3;
	b3.Push(12);
	b3.Push(13);
	b3.Push(14);
	b1 = b3;
	cout << "Оператор присваивания:" << endl;
	for (int i = 0; i < b1.GetSize(); i++)
	{
		cout << b1[i] << endl;
	}
	AQueue* a2, *a3;
	a2 = new AQueue(2);
	a3 = new AQueue(3);
	a3->Push(12);
	a3->Push(13);
	a3->Push(14);
	*a2 = *a3;
	cout << "Работоспособность с динамическими объектами:" << endl;
	for (int i = 0; i < b1.GetSize(); i++)
	{
		cout << a2->GetByIndex(i) << endl;
	}
	system("pause");
	return 0;
}