#include "matrix.h"
using namespace std;

Matrix::Matrix(int tn, int tm)
{
	n = tn;
	m = tm;
	p = new double*[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = new double[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &temp)
{
	n = temp.n;
	m = temp.m;
	p = new double*[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = new double[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] = temp.p[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < n; i++)
	{
		delete[] p[i];
	}
	delete[] p;
}

Matrix Matrix::operator=(const Matrix &temp)
{
	if (this == &temp)
	{
		return (*this);
	}
	(*this).~Matrix();
	n = temp.n;
	m = temp.m;
	p = new double*[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = new double[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] = temp.p[i][j];
		}
	}
	return (*this);
}

Matrix Matrix::operator+=(const Matrix &temp)
{
	if (n != temp.n || m != temp.n)
	{
		throw MatrixException("Операция сложения невозможна. Разный размер матриц.\n");
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] += temp.p[i][j];
		}
	}
	return (*this);
}

Matrix Matrix::operator-=(const Matrix &temp)
{
	if (n != temp.n || m != temp.n)
	{
		throw MatrixException("Операция вычитания невозможна. Разный размер матриц.\n");
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] -= temp.p[i][j];
		}
	}
	return (*this);
}

Matrix Matrix::operator*=(const Matrix &temp)
{

	if (m != temp.n)
	{
		throw MatrixException("Операция умножения невозможна. Разный размеры матриц не соответствуют.\n");
	}
	Matrix t(*this);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			p[i][j] = 0;
			for (int x = 0; x < n; x++)
			{
				p[i][j] += (t.p[i][x] * temp.p[x][j]);
			}
		}
	return (*this);
}

Matrix Matrix::operator*=(const double x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] *= x;
		}
	}
	return (*this);
}

Matrix Matrix::operator/=(const double x)
{
	if (x==0)
	{
		throw MatrixException("Деление на 0!\n");
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] /= x;
		}
	}
	return (*this);
}

Matrix Matrix::operator / (const double x)
{
	if (x == 0)
	{
		throw MatrixException("Деление на 0!\n");
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] /= x;
		}
	}
	return (*this);
}
Matrix Matrix::operator / (const int x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] /= x;
		}
	}
	return (*this);
	
}
Matrix Matrix::operator * (const int x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] *= x;
		}
	}
	return (*this);
}

Matrix Matrix::operator * (const double x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] *= x;
		}
	}
	return (*this);
}

Matrix Matrix::operator*(const Matrix &temp) const
{
	if (m != temp.n)
	{
		throw MatrixException("Операция умножения невозможна. Разный размеры матриц не соответствуют.\n");
	}
	Matrix t1 = (*this);
	t1 *= temp;
	return t1;
}

Matrix Matrix::operator+(const Matrix &temp) const
{
	if (n != temp.n || m != temp.n)
	{
		throw MatrixException("Операция сложения невозможна. Разный размер матриц.\n");
	}
	Matrix t = (*this);
	t += temp;
	return t;
}

Matrix Matrix::operator-(const Matrix &temp) const
{
	if (n != temp.n || m != temp.n)
	{
		throw MatrixException("Операция вычитания невозможна. Разный размер матриц.\n");
	}
	Matrix t = (*this);
	t -= temp;
	return t;
}

bool Matrix::operator==(const Matrix &temp) const
{
	if (n != temp.n || m != temp.m)
	{
		throw MatrixException("Операция сравнения невозможна. Разный размер матриц.\n");
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; i++)
		{
			if (p[i][j] != temp.p[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

bool Matrix::operator!=(const Matrix &temp) const
{
	if (n != temp.n || m != temp.m)
	{
		throw MatrixException("Операция неравенства невозможна. Разный размер матриц.\n");
	}
	if ((*this) == temp)
	{
		return false;
	}
	return true;
}

Matrix operator*(const double x, const Matrix &temp)
{
	Matrix t = temp;
	t *= x;
	return t;;
}

istream & operator>>(istream &in, Matrix &temp)
{
	int x, z;
	cout << "Enter your matrix components (" << (temp.n*temp.m) << "):" << endl;
	for (int i = 0; i < temp.n; i++)
	{
		for (int j = 0; j < temp.m; j++)
		{
			in >> temp.p[i][j];
		}
	}
	system("cls");
	cout << "Matrix(" << temp.n << "x" << temp.m << ")" << endl;
	return in;
}

ostream & operator<<(ostream &out, const Matrix &temp)
{
	for (int i = 0; i < temp.n; i++)
	{
		for (int j = 0; j < temp.m; j++)
		{
			out << setw(10) << round((temp.p[i][j])*100) / 100;
		}
		out << endl;
	}
	return out;
}