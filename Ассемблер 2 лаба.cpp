#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int* arr;
	int count;
	int gr1, gr2;
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	cout << "Введите число элементов массива: " << endl;
	cin >> count;
	cout << "Введите первую границу рандома: " << endl;
	cin >> gr1;
	cout << "Введите вторую границу рандома: " << endl;
	cin >> gr2;
	if (gr1>gr2)
	{
		swap(gr1, gr2);
	}
	arr = new int[count];
	cout << "Исходный массив: " << endl;
	for (int i = 0; i < count; i++)
	{
		arr[i] = rand() % (gr2 - gr1 + 1) + gr1;
		cout << arr[i] << endl;
	}
	int num = 0;
	int abc;
	_asm
	{
		mov esi, arr;
		mov edx, 0;
		mov ecx, 0;
		first:
		mov eax, [esi + 4 * ecx];
		inc num;
		mov ebx, ecx;
		cmp ecx, 0;
		je skip;
		second:
		dec ecx;
		mov edx, [esi + 4 * ecx];
		cmp eax, edx;
		jne _next
		dec num;
		jmp skip;
		_next:
		cmp ecx, 0;
		ja second;
		skip:
		mov ecx, ebx;
		inc ecx;
		cmp ecx, count;
			jb first;
		
	}
	cout << "Количество различных элементов: " << endl;
	cout << num << endl;
	system("pause");
	return 0;
}