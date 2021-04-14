#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	try
	{
		setlocale(LC_ALL, "rus");
		//Matrix matr1(2,2), matr2(2,2);
		//cin >> matr1;
		//cout << matr1;
		//cin >> matr2;
		//cout << matr2;
		//system("cls");
		//cout << (matr1 + matr2)*(matr1 - matr2);
	}
	catch(MatrixException &e)
	{
		cerr << e.getError() << endl;
	}
	system("pause");
	return 0;
}