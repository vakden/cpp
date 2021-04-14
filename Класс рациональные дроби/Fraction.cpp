#include "Fraction.h"
#include <iostream>

	using namespace std;
	int inden = 1;
	Fraction::Fraction()
	{
		a = 0;
		b = 1;
		ind = inden;
		inden++;
	};
Fraction::Fraction(int A)
	{
		a = A;
		b = 1;
		ind = inden;
		inden++;
	}
	Fraction::Fraction(int A, int B)
	{
		a = A;
		b = B;
		ind = inden;
		inden++;
		(*this).sokr(*this);
	}
	Fraction::Fraction(Fraction &c)
	{
		a = c.a;
		b = c.b;
	}
	Fraction &Fraction::operator = (const Fraction &c)
	{
		if (&c != this)
		{
			a = c.a;
			b = c.b;
		}
		return (*this);
	}
	Fraction &Fraction::operator = (int &c)
	{
		a += c*b;
		return (*this);
	}
	Fraction &Fraction::operator + (Fraction &c)
	{
		Fraction temp;
		temp.a = a*c.b + b*c.a;
		temp.b = b*c.b;
		temp.sokr(temp);
		temp.ind = inden;
		inden++;
		return temp;
	}
	Fraction &Fraction::operator - (Fraction &c)
	{
		Fraction temp;
		temp.a = a*c.b - b*c.a;
		temp.b = b*c.b;
		temp.sokr(temp);
		temp.ind = inden;
		inden++;
		return temp;
	}
	Fraction &Fraction::operator * (Fraction &c)
	{
		Fraction temp;
		temp.a = a*c.a;
		temp.b = b*c.b;
		temp.sokr(temp);
		temp.ind = inden;
		inden++;
		return temp;
	}
	Fraction &Fraction::operator / (Fraction &c)
	{
		Fraction temp;
		temp.a = a*c.b;
		temp.b = b*c.a;
		temp.sokr(temp);
		temp.ind = inden;
		inden++;
		return temp;
	}
	bool Fraction:: operator == (const Fraction &c) const
	{
		return ((a == c.a) && (b == c.b));
	}
	bool Fraction:: operator != (const Fraction &c) const
	{
		return ((a != c.a) || (a != c.a));
	}
	bool Fraction:: operator >= (const Fraction &c) const
	{
		return (a*c.b >= c.a*b);
	}
	bool Fraction:: operator <= (const Fraction &c) const
	{
		return (a*c.b <= c.a*b);
	}
	bool Fraction:: operator < (const Fraction &c) const
	{
		return (a*c.b < c.a*b);
	}
	bool Fraction:: operator > (const Fraction &c) const
	{
		return (a*c.b > c.a*b);
	}
	Fraction & Fraction::operator ! ()
	{
		Fraction temp;
		temp.a = b;
		temp.b = a;
		temp.sokr(temp);
		temp.ind = inden;
		inden++;
		return temp;
	}
	Fraction & Fraction::operator - ()
	{
		Fraction temp;
		temp.a = -a;
		temp.sokr(temp);
		temp.ind = inden;
		inden++;
		return temp;
	}
	Fraction & Fraction::operator ++ ()
	{
		Fraction temp;
		temp.a = a+b;
		temp.sokr(temp);
		temp.ind = inden;
		inden++;
		return temp;
	}
	Fraction & Fraction::operator -- ()
	{
		Fraction temp;
		temp.a = a - b;
		temp.sokr(temp);
		return temp;
	}
	Fraction & Fraction::operator -- (int)
	{
		Fraction temp;
		temp.a = a - b;
		temp.sokr(temp);
		return temp;
	}
	Fraction & Fraction::operator ++ (int)
	{
		Fraction temp;
		temp.a = a + b;
		temp.sokr(temp);
		temp.ind = inden;
		inden++;
		return temp;
	}
	ostream &operator<<(ostream &out, Fraction &c)
	{
		c.sokr(c);
		out << c.a;
			out << '/';
			out << c.b;
		return out;
	}
	istream &operator>>(istream &in, Fraction &c)
	{
		char S;
		in >> c.a;
		in.get(S);
		if (S == '/')
			in >> c.b;
		else
			cin.putback(S);
		c = Fraction(c.a, c.b);
		c.sokr(c);
		return in;
	}
	Fraction operator + (int t, Fraction &c)
	{
		Fraction temp;
		temp.a = t*c.b + c.a;
		temp.sokr(temp);
		temp.ind = inden;
		inden++;
		return temp;
	}
	Fraction operator - (int t, Fraction &c)
	{
		Fraction temp;
		temp.a = c.a - t*c.b;
		temp.sokr(temp);
		temp.ind = inden;
		inden++;
		return temp;
	}
	Fraction operator * (int t, Fraction &c)
	{
		Fraction temp;
		temp.a = c.a*t;
		temp.sokr(temp);
		temp.ind = inden;
		inden++;
		return temp;
	}
	Fraction operator / (int t, Fraction &c)
	{
		Fraction temp;
		temp.b = c.b*t;
		temp.sokr(temp);
		temp.ind = inden;
		inden++;
		return temp;
	}
	Fraction & Fraction::operator +(int &c)
	{
		a = a + b*c;
		(*this).sokr(*this);
		return *this;
	}
	Fraction & Fraction::operator -(int &c)
	{
		a = a - b*c;
		(*this).sokr(*this);
		return *this;
	}
	Fraction & Fraction::operator *(int &c)
	{
		a = a*c;
		(*this).sokr(*this);
		return *this;
	}
	Fraction & Fraction::operator /(int &c)
	{
		b = b*c;
		(*this).sokr(*this);
		return *this;
	}
	Fraction &Fraction::operator += (Fraction &c)
	{
		a = a*c.b + c.a*b;
		b = b*c.b;
		(*this).sokr(*this);
		return (*this);
	}
	Fraction &Fraction::operator -= (Fraction &c)
	{
		a = a*c.b - c.a*b;
		b = b*c.b;
		(*this).sokr(*this);
		return (*this);
	}
	Fraction &Fraction::operator *= (Fraction &c)
	{
		a *= c.a;
		b *= c.b;
		(*this).sokr(*this);
		return (*this);
	}
	Fraction &Fraction::operator /= (Fraction &c)
	{
		a *= c.b;
		b *= c.a;
		(*this).sokr(*this);
		return (*this);
	}
	Fraction &Fraction::operator /= (int &c)
	{
		b *= c;
		(*this).sokr(*this);
		return (*this);
	}
	Fraction &Fraction::operator += (int &c)
	{
		a = a + c*b;
		(*this).sokr(*this);
		return (*this);
	}
	Fraction &Fraction::operator -= (int &c)
	{
		a = a - c*b;
		(*this).sokr(*this);
		return (*this);
	}
	Fraction &Fraction::operator *= (int &c)
	{
		a = a*c;
		(*this).sokr(*this);
		return (*this);
	}


