#include "Complex.h"
#include <iostream>

	using namespace std;


	Complex::Complex(double r) 
	{
		re = r;
		im = 0;
	}
	Complex::Complex(double r, double i) 
	{
		re = r;
		im = i;
	}
	Complex::Complex(Complex &c) 
	{
		re = c.re;
		im = c.im;
	}
	Complex &Complex::operator = (Complex &c) 
	{
		re = c.re;
		im = c.im;
		return (*this);
	}
	Complex Complex::operator + (Complex &c) 
	{
		Complex temp;
		temp.re = re + c.re;
		temp.im = im + c.im;
		return temp;
	}
	Complex Complex::operator - (Complex &c) 
	{
		Complex temp;
		temp.re = re - c.re;
		temp.im = im - c.im;
		return temp;
	}
	Complex Complex::operator * (Complex &c) 
	{
		Complex temp;
		temp.re = re*c.re-im*c.im;
		temp.im = re*c.im;
		return temp;
	}
	Complex Complex::operator / (Complex &c) 
	{
		Complex temp;
		double r = c.re * c.re + c.im * c.im;
		if (r == 0)
		{
			throw "Oshibka! Delenye na 0!";
		}
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
	ostream &operator<<(ostream &out, Complex &c)
	{
		out << c.re;
		if (c.im > 0)
		{
			out << "+";
		}
		out << c.im << "i";
		return out;
	}
	istream &operator>>(istream &in, Complex &c)
	{
		in >> c.re >> c.im;
		return in;
	}


