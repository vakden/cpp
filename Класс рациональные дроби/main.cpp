#include <iostream>
#include "Fraction.h"
#include <ctime>

using namespace std;

int main()
{
	try
	{
		srand(time(NULL));
		setlocale(LC_ALL, "rus");
		Fraction drobi[8];
		drobi[0] = Fraction(rand() % 10 + 1, rand() % 10 + 1);
		drobi[1] = Fraction(rand() % 10 + 1, rand() % 10 + 1);
		for (int i = 2; i < 5; i++)
		{
			drobi[i] = drobi[i - 1] + drobi[i - 2];
		}
		for (int i = 5; i < 8; i++)
		{
			drobi[i] = -2*drobi[i-5] + drobi[i - 3];
		}
		for (int i = 0; i < 8; i++)
		{
			cout << drobi[i] << " " << drobi[i].ind << endl;	
		}
		Fraction max = drobi[0];
		int maxi = 0;
		for (int i = 0; i < 8; i++)
		{
			if (drobi[i].ind % 2 == 0)
			{
				if (drobi[i] > max)
				{
					maxi = i+1;;
					max = drobi[i];
				}
			}
		}
		cout << "Максимальная дробь с идентификатором "<< maxi << endl;
	}
	catch (Exception &exception)
	{
		cerr << exception.getError() << endl;
	}
	system("pause");
	return 0;
}