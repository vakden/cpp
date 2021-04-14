#pragma once
#include <iostream>
#include <string>

using namespace std;

const int number = 6;//(number-1)*4 = количество знаков

class BigInt
{
private:
    short int data[number];
public:
	BigInt();
	BigInt(int& c);
	BigInt(BigInt&c);
	friend ostream &operator<<(ostream&, BigInt&);
	friend istream& operator >> (istream&, BigInt&);
	BigInt operator + (BigInt&) const;
	BigInt operator - (BigInt&) const;
	BigInt operator + (int&) const;
	BigInt operator - (int&) const;
	BigInt operator + (const int&) const;
	BigInt operator - (const int&) const;
	BigInt BigInt::operator += (BigInt&);
	BigInt BigInt::operator -= (BigInt&);
	BigInt BigInt::operator += (int&);
	BigInt BigInt::operator -= (int&);
	BigInt BigInt::operator += (const int&);
	BigInt BigInt::operator -= (const int&);
	BigInt operator = (BigInt&);
	BigInt operator = (int&);
	BigInt operator = (const int&);
    bool operator == (BigInt&c) const;
	bool operator != (BigInt&c) const;
	bool operator >= (BigInt&c) const;
	bool operator <= (BigInt&c) const;
	bool operator > (BigInt&c) const;
	bool operator < (BigInt&c) const;
	bool operator == (int&c) const;
	bool operator != (int&c) const;
	bool operator >= (int&c) const;
	bool operator <= (int&c) const;
	bool operator > (int&c) const;
	bool operator < (int&c)const;
	bool operator == (const int&c)const;
	bool operator != (const int&c)const;
	bool operator >= (const int&c)const;
	bool operator <= (const int&c)const;
	bool operator > (const int&c)const;
	bool operator < (const int&c)const;
	BigInt BigInt::operator ++ ();
	BigInt BigInt::operator -- ();
	BigInt BigInt::operator ++ (int);
	BigInt BigInt::operator -- (int);
};