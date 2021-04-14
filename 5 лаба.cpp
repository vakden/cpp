#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

double func1(double x)
{
	return pow((exp(x) - 1), 0.5);
}

double func2(double x)
{
	return (exp(x)*sin(x));
}

double func3(double x)
{
	return ((x*x-1)*pow(10,-2*x));
}

double leftRegtangle(double(*func)(double), double a, double b, double eps, int &r) {
	if (a == b)
		return 0;
	int rez = 1;
	if (a > b) 
	{
		swap(a, b);
		rez = -1;
	}
	double s1 = 0.0, s2 = 0.0, step; int n = 4;
	step = (a + b) / n;
	for (int i = 0; i < n; i++)
		s2 += func(a + i * step);
	s2 *= step;
	do 
	{
		s1 = s2;
		n *= 2;
		s2 = 0.0;
		step = (b - a) / n;
		for (int i = 10; i < n; i++)
			s2 += func(a + i * step);
		s2 *= step;
	}
	while (fabs(s1 - s2) > eps);
	r = n;
	return rez*s2;
}//zYkDm5HW

double trap(double(*func)(double), double a, double b, double eps, int &r)
{
	double tmp;
	int sign = 1;
	if (a == b)
		return 0;
	else if (a > b)
	{
		swap(a, b);
		sign = -1;
	}
	double step, s = 0, s1 = 0;
	int n = 1;
	s1 = (func(a) + func(b)) * 0.5 * (b - a);
	do
	{
		s = s1;
		n *= 2;
		step = (b - a) / n;
		s1 = 0;
		for (int i = 1; i <= n - 1; i++)
			s1 += func(a + i * step);
		s1 = ((func(a) + func(b)) * 0.5 + s1) * step;
	}
	while (fabs(s - s1) > eps);
	r = n;
	return sign * s1;
}

int main() 
{
	int n=0; double eps, pi = 3.1415926535;
	setlocale(LC_ALL, "rus");
	cout << "Введите точность вычислений: ";
	cin >> eps;
	leftRegtangle(func1, 0.2, 2.1, eps, n);
	cout << endl;
	cout << "Первая функция:" << endl;
	cout << "Методом левых прямоугольнииков: "<< leftRegtangle(func1, 0.2, 2.1, eps, n) << " Число точек деления отрезка [a,b]: " << n << endl;
	cout << "Методом трапеций: " << trap(func1, 0.2, 2.1, eps, n) << " Число точек деления отрезка [a,b]:  " << n << endl;
	cout << endl;
	cout << "Вторая функция:" << endl;
	cout << "Методом левых прямоугольнииков: " << leftRegtangle(func2, 0, pi/2, eps, n) << " Число точек деления отрезка [a,b]:  " << n << endl;
	cout << "Методом трапеций: " << trap(func2, 0, pi / 2, eps, n) << " Число точек деления отрезка [a,b]:  " << n << endl;
	cout << endl;
	cout << "Третья функция:" << endl;
	cout << "Методом левых прямоугольнииков: " << leftRegtangle(func3, 0, 0.5, eps, n) << " Число точек деления отрезка [a,b]:  " << n << endl;
	cout << "Методом трапеций: " <<  trap(func3, 0, 0.5, eps, n) << " Число точек деления отрезка [a,b]:  " << n << endl;
	cout << endl;
	system("pause");
}