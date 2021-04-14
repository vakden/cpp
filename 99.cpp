#include<iostream>
using namespace std;

void main()
{
	int i = 1000, a, b, c, d;
	int n = 1000;
	for (; i <= 9999; i++)
	{
		d = n % 10;
		c = (n / 10) % 10;
		b = (n / 100) % 10;
		a = (n / 1000);
		if ((a != b) && (b != c) && (c != d) && (a != c) && (a != d) && (b != d))
			cout << n << endl;



		n++;
	}




	system("pause");
}