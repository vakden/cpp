#include<iostream>
#include<math.h>
using namespace std;

void main()
{
	int a, b, c, i;
	for (i = 100; i <= 999; i++)
	{
		a = i / 100;
		b = i / 10 - a * 10;
		c = i % 10;
		if ((pow(a, 3) + pow(b, 3) + pow(c, 3)) == i)
			cout << i << endl;
	}
	system("pause");
}