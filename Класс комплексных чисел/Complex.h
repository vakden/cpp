#pragma once
 #include <iostream>
using namespace std;
class Complex
{
	double im, re;
public:
	Complex() {};
	~Complex() {};
	Complex(double r); 
	Complex(double r, double i); 
	Complex(Complex &c); 
	Complex &operator = (Complex &c); 
	Complex Complex::operator + (Complex &c); 
	Complex Complex::operator - (Complex &c);  
	Complex Complex::operator * (Complex &c); 
	Complex Complex::operator / (Complex &c); 
	bool Complex:: operator == (const Complex &c) const;
	bool Complex:: operator != (const Complex &c) const;
	friend ostream &operator<<(ostream &, Complex &); 
	friend istream &operator>>(istream &, Complex &); 
};

