#pragma once
#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include <assert.h>
#include <iomanip>
using namespace std;



class MatrixException
{
private:
	string error;
public:
	MatrixException(string eerror) : error(eerror) { assert(eerror.length() != 0); }
	const char* getError() { return error.c_str(); }
};

class Matrix
{
private:
	int n, m;
	double **p;
public:
	Matrix() : n(1), m(1)
	{
		p = new double*[n];
		p[0] = new double[m];
		p[0][0] = 0;
	};
	Matrix(int, int);
	Matrix(const Matrix &);
	~Matrix();
	Matrix operator =(const Matrix&);
	Matrix operator +=(const Matrix&);
	Matrix operator -=(const Matrix&);
	Matrix operator *=(const Matrix&);
	Matrix operator *=(const double);
	Matrix operator /=(const double);
	Matrix operator / (const double x);
	Matrix operator * (const double x);
	Matrix operator / (const int x);
	Matrix operator * (const int x);
	friend Matrix operator *(const double, const Matrix&);
	Matrix operator *(const Matrix&) const;
	Matrix operator +(const Matrix&) const;
	Matrix operator -(const Matrix&) const;
	bool operator ==(const Matrix&)const;
	bool operator !=(const Matrix&)const;
	friend std::istream& operator >> (std::istream&, Matrix&);
	friend std::ostream& operator << (std::ostream&, const Matrix&);
};
