#include <iostream>
#include "MyArray.h"
using namespace std;

int main(int arg, char* args)
{
	int* a;
	a = new int[3];
	a[0] = 1; a[1] = 2; a[2] = 3;
	int b[3] = {2,2,2};
	MyArray<int> arr1(3, a);
	MyArray<int> arr2(3, b);
	for (int i = 0; i < 3; i++)
	{
		cout << arr1.data[i] << endl;
	}
	cout << endl;
	arr1 += arr2;
	for(int i = 0; i < 6; i++)
	{
		cout << arr1.data[i] << endl;
	}
	
	system("pause");
	return 0;
}