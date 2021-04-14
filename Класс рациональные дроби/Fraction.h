#pragma once
 #include <iostream>
using namespace std;

#include <string>

class Exception
{
private:
	string m_error;

public:
	Exception(string error)
		: m_error(error)
	{
	}

	const char* getError() { return m_error.c_str(); }
};


class Fraction
{
	int a, b;
	Fraction sokr(Fraction c)
	{
		if ((a < 0) && (b < 0))
		{
			a = -a;
			b = -b;
		}
		if ((a > 0) && (b < 0))
		{
			a = -a;
			b = -b;
		}
		if (b == 0)
		{
			throw Exception("Error, denominator = 0!");
		}
		if (a == 0)
		{
			b = 1;
		}
		if (abs(a) >= abs(b))
		{
			for(int i = abs(b); i > 0; i--)
			{
				if (((abs(a) % i) == 0) && ((abs(b) % i) == 0))
				{
					a /= i;
					b /= i;
				}
			}
		}
		else
		{
			for (int i = abs(a); i > 0; i--)
			{
				if (((abs(a) % i) == 0) && ((abs(b) % i) == 0))
				{
					a /= i;
					b /= i;
				}
			}
		}
		return (*this);
	}
public:
	int ind;
	Fraction Geta()
	{
		return a;
	};
	Fraction Getb()
	{
		return b;
	};
	void Seta(int a)
	{
		this->a = a;
	};
	void Setb(int b)
	{
		this->b = b;
	};
	Fraction();
	Fraction(int A);
	Fraction(int A, int B); 
	Fraction(Fraction &c); 
	Fraction &operator = (const Fraction &c);
	Fraction &Fraction::operator = (int &c);
	Fraction &Fraction::operator + (Fraction &c);
	Fraction &Fraction::operator - (Fraction &c);
	Fraction &Fraction::operator * (Fraction &c);
	Fraction &Fraction::operator / (Fraction &c);
	Fraction & Fraction::operator ! ();
	Fraction & Fraction::operator - ();
	Fraction & Fraction::operator ++ ();
	Fraction & Fraction::operator -- ();
	Fraction & Fraction::operator ++ (int);
	Fraction & Fraction::operator -- (int);
	bool Fraction:: operator == (const Fraction &c) const;
	bool Fraction:: operator != (const Fraction &c) const;
	bool Fraction:: operator >= (const Fraction &c) const;
	bool Fraction:: operator <= (const Fraction &c) const;
	bool Fraction:: operator < (const Fraction &c) const;
	bool Fraction:: operator > (const Fraction &c) const;
	friend ostream &operator<<(ostream &, Fraction &);
	friend istream &operator>>(istream &, Fraction &);
	friend Fraction operator + (int t, Fraction &c);
	friend Fraction operator - (int t, Fraction &c);
	friend Fraction operator * (int t, Fraction &c);
	friend Fraction operator / (int t, Fraction &c);
	Fraction & Fraction::operator +(int &c);
	Fraction & Fraction::operator -(int &c);
	Fraction & Fraction::operator *(int &c);
	Fraction & Fraction::operator /(int &c);
	Fraction &Fraction::operator += (Fraction &c);
	Fraction &Fraction::operator -= (Fraction &c);
	Fraction &Fraction::operator *= (Fraction &c);
	Fraction &Fraction::operator /= (Fraction &c);
	Fraction &Fraction::operator += (int &c);
	Fraction &Fraction::operator -= (int &c);
	Fraction &Fraction::operator *= (int &c);
	Fraction &Fraction::operator /= (int &c);
	operator double()
	{
		return (double (a / b));
	}
	
};

