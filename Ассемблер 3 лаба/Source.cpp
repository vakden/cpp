#include <iostream>
#include <ctime>

using namespace std;

extern "C"
{
	int count, N;
	int min;
	void __cdecl Function(int*, int, int);
	void __stdcall Function1(int*, int, int);
	void __fastcall Function2(int*, int, int);
}

const int MAXN = 100;
int* arr1 = new int[MAXN];
int* arr2 = new int[MAXN];
int* arr3 = new int[MAXN];

int main()
{
	int N= 0;
	int count;
	int gr1, gr2;
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	cout << "������� ����� ��������� �������(�� ����� 100): " << endl;
	cin >> count;
	if (count>100)
	{
		count = 100;
	}
	if (N > count)
	{
		N = count;
	}
	cout << "������� ������ ������� �������: " << endl;
	cin >> gr1;
	cout << "������� ������ ������� �������: " << endl;
	cin >> gr2;
	if (gr1 > gr2)
	{
		swap(gr1, gr2);
	}
	cout << "�������� ������: " << endl;
	for (int i = 0; i < count; i++)
	{
		arr1[i] = (rand() % (gr2 - gr1 + 1) + gr1);
		arr2[i] = arr3[i] = arr1[i];
		cout << arr1[i] << endl;
	}
	min = arr1[0];
	int temp = N;
	int tmp = count;
	Function(arr1, count, N);
	cout << "��������� ������ _cdecl: " << endl;
	for (int i = 0; i < count; i++)
	{
		cout << arr1[i] << endl;
	}
	N = temp;
	count = tmp;
	Function1(arr2, count, N);
	cout << "��������� ������ _stdcall: " << endl;
	for (int i = 0; i < count; i++)
	{
		cout << arr2[i] << endl;
	}
	N = temp;
	count = tmp;
	Function2(arr3, count, N);
	cout << "��������� ������ _fastcall: " << endl;
	for (int i = 0; i < count; i++)
	{
		cout << arr3[i] << endl;
	}
	/*delete[] arr1; delete[] arr2; delete[] arr3;*/
	system("pause");
	return 0;
}