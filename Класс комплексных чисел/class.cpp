#include <iostream>
#include "Header.h"

using namespace std;


	Complex::Complex(double r) // ����������� �� ���������
	{
		re = r;
		im = 0;
	}
	Complex:: Complex(double r, double i) // ����������� �� ���������
	{
		re = r;
		im = i;
	}
	Complex:: Complex(Complex &c) // ����������� �����������
	{
		re = c.re;
		im = c.im;
	}
	Complex::Complex &operator = (Complex::Complex &c) const // ���������� ��������� ������������
	{
		re = c.re;
		im = c.im;
		return (*this);
	}
	Complex::Complex Complex::operator + (Complex &c) // ���������� ��������� ��������
	{
		Complex temp;
		temp.re = re + c.re;
		temp.im = im + c.re;
		return temp;
	}
	Complex::Complex Complex::operator - (Complex &c) // ���������� ��������� ���������
	{
		Complex temp;
		temp.re = re - c.re;
		temp.im = im - c.re;
		return temp;
	}
	Complex::Complex Complex::operator * (Complex &c) // ���������� ��������� ���������
	{
		Complex temp;
		temp.re = re*c.re;
		temp.im = re*c.im;
		return temp;
	}
	Complex::Complex Complex::operator / (Complex &c) // ���������� ��������� �������
	{
		Complex temp;
		double r = c.re * c.re + c.im * c.im;
		temp.re = (re * c.re + im * c.im) / r;
		temp.im = (im * c.re - re * c.im) / r;
		return temp;
	}
	bool Complex:: operator == (const Complex &c) const
	{
		return ((re == c.re) && (im == c.im));
	}
	bool Complex:: operator != (const Complex &c) const
	{
		return ((re != c.re) || (im != c.im));
	}
	ostream &operator<<(ostream &out, const Complex &c)
	{
		out << c.re;
		if (c.im > 0)
		{
			out << "+";
		}
		out << c.im << "i";
		return out;
	}
	istream &operator>>(istream &in, const Complex &c)
	{
		in >> c.re >> c.im;
		return in;
	}
