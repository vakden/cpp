#include "Header.h"

using namespace std;


BigInt::BigInt()
{
	for (int i = 0; i < number; i++)
	{
		data[i] = 0;
	}
}
BigInt::BigInt(int& c)
{
	for (int i = 0; i < number; i++)
	{
		data[i] = 0;
	}
	data[number - 3] = (c - (c % 100000000));
	data[number - 2] = (c - (c % 10000) - (c - (c % 100000000)));
	data[number - 1] = (c % 10000);
}
ostream &operator<<(ostream &out, BigInt&c)
	{
		if (c == 0)
		{
			out << "0";
			return out;
		}
		int a = 0;
		for (int i = 0; i < number; i++)
		{
			if (c.data[i] == 0)
			{
				if (a > 0)
				{
					out << "0000";
					a++;
				}
			}
			else if (c.data[i] < 10)
			{
				if (a > 0)
				{
					out << "000" << c.data[i];
					a++;
				}
				if (a == 0)
				{
					out << c.data[i];
					a++;
				}
			}
			else if (c.data[i] < 100)
			{
				if (a > 0)
				{
					out << "00" << c.data[i];
					a++;
				}
				if (a == 0)
				{
					out << c.data[i];
					a++;
				}
			}
			else if (c.data[i] < 1000)
			{
				if (a > 0)
				{
					out << "0" << c.data[i];
					a++;
				}
				if (a == 0)
				{
					out << c.data[i];
					a++;
				}
			}
			else
			{
				out << c.data[i];
				a++;
			}
		}
		return out;
	}
istream& operator >> (istream& in, BigInt& c)
{
	
		string a;
		in >> a;
		if (a.length() > (number - 1)*4)
		{
			a = a.substr(0, 80);
		}
		else
		{

			while (a.length() != (number-1)*4)
			{
				a = '0' + a;
			}
		}
		int j = 1;
		c.data[0] = 0;
		for (int i = 0; i < (number-1)*4; i += 4)
		{
			string b;
			b = a.substr(i, 4);
			c.data[j] = atoi(b.c_str());
			j++;
		}
		return in;
}
BigInt::BigInt(BigInt&c)
{
	for (int i = 0; i <= number; i ++)
	{
		data[i] = c.data[i];
	}
}
BigInt BigInt::operator + (BigInt&c)const
{
	BigInt temp;
	for (int i = 0; i < number; i++)
	{
		temp.data[i] = data[i] + c.data[i];
		if (temp.data[i] > 9999)
		{
			temp.data[i] -= 10000;
			temp.data[i - 1]++;
		}
	}
	return temp;
}
BigInt BigInt::operator - (BigInt&c)const
{
	BigInt temp;
	temp = 0;
	if (*this < c)
	{
		cerr << "Вычитаемое больше уменьшаемого!" << endl;
		return temp;
	}
	for (int i = 0; i < number; i++)
	{
		temp.data[i] = data[i] - c.data[i];
		if (temp.data[i] < 0)
		{
			temp.data[i] += 10000;
			temp.data[i - 1]--;
		}
	}
	return temp;
}
BigInt BigInt::operator + (int&c)const
{
	BigInt temp;
	temp.data[number - 3] = data[number - 3] + (c - (c % 100000000));
	if (temp.data[18] > 9999)
	{
		temp.data[number - 3] -= 10000;
		temp.data[number - 4]++;
	}
	temp.data[number - 2] = data[number - 2] + (c - (c % 10000) - (c % 100000000));
	if (temp.data[number - 2] > 9999)
	{
		temp.data[number - 2] -= 10000;
		temp.data[number - 3]++;
	}
	temp.data[number - 1] = data[number - 1] + (c % 10000);
	if (temp.data[number - 1] > 9999)
	{
		temp.data[number - 1] -= 10000;
		temp.data[number - 2]++;
	}
	return temp;
}
BigInt BigInt::operator - (int&c)const
{
	BigInt temp;
	temp = 0;
	if (*this < c)
	{
		cerr << "Вычитаемое больше уменьшаемого!" << endl;
		return temp;
	}
	temp.data[number - 3] = data[number - 3] - (c - (c % 100000000));
	if (temp.data[number - 3] < 0)
	{
		temp.data[number - 3] += 10000;
		temp.data[number - 4]--;
	}
	temp.data[number - 2] = data[number - 2] - (c - (c % 10000) - (c % 100000000));
	if (temp.data[number - 2] < 0)
	{
		temp.data[number - 2] += 10000;
		temp.data[number-3]--;
	}
	temp.data[number -1] = data[number-1] - (c % 10000);
	if (temp.data[number-1] < 0)
	{
		temp.data[number-1] += 10000;
		temp.data[number-2]--;
	}
	return temp;
}
BigInt BigInt::operator + (const int&c)const
{
	BigInt temp;
	temp.data[number-3] = data[number-3] + (c - (c % 100000000));
	if (temp.data[number-3] > 9999)
	{
		temp.data[number-3] -= 10000;
		temp.data[number-4]++;
	}
	temp.data[number-2] = data[number-2] + (c - (c % 10000) - (c % 100000000));
	if (temp.data[number-2] > 9999)
	{
		temp.data[number-2] -= 10000;
		temp.data[number-3]++;
	}
	temp.data[number-1] = data[number-1] + (c % 10000);
	if (temp.data[number-1] > 9999)
	{
		temp.data[number-1] -= 10000;
		temp.data[number-2]++;
	}
	return temp;
}
BigInt BigInt::operator - (const int&c)const
{
	BigInt temp;
	temp = 0;
	if (*this < c)
	{
		cerr << "Вычитаемое больше уменьшаемого!" << endl;
		return temp;
	}
	temp.data[number-3] = data[number-3] - (c - (c % 100000000));
	if (temp.data[number-3] < 0)
	{
		temp.data[number-3] += 10000;
		temp.data[number-3]--;
	}
	temp.data[number-2] = data[number-2] - (c - (c % 10000) - (c % 100000000));
	if (temp.data[number-2] < 0)
	{
		temp.data[number-2] += 10000;
		temp.data[number-3]--;
	}
	temp.data[number-1] = data[number-1] - (c % 10000);
	if (temp.data[number-1] < 0)
	{
		temp.data[number-1] += 10000;
		temp.data[number-2]--;
	}
	return temp;
}
BigInt BigInt::operator += (BigInt&c)
{
	for (int i = 0; i < number; i++)
	{
		data[i] = data[i] + c.data[i];
		if (data[i] > 9999)
		{
			data[i] -= 10000;
			data[i - 1]++;
		}
	}
	return *this;
}
BigInt BigInt::operator -= (BigInt&c)
{
	if (*this < c)
	{
		*this = 0;
		cerr << "Вычитаемое больше уменьшаемого!" << endl;
		return *this;
	}
	for (int i = 0; i < number; i++)
	{
		data[i] = data[i] - c.data[i];
		if (data[i] < 0)
		{
			data[i] += 10000;
			data[i - 1]--;
		}
	}
	return *this;
}
BigInt BigInt::operator += (int&c)
{
	data[number-3] = data[number-3] + (c - (c % 100000000));
	if (data[number-3] > 9999)
	{
		data[number-3] -= 10000;
		data[number-4]++;
	}
	data[number-2] = data[number-2] + (c - (c % 10000) - (c % 100000000));
	if (data[number-2] > 9999)
	{
		data[number-2] -= 10000;
		data[number-3]++;
	}
	data[number-1] = data[number-1] + (c % 10000);
	if (data[number-1] > 9999)
	{
		data[number-1] -= 10000;
		data[number-2]++;
	}
	return *this;
}
BigInt BigInt::operator -= (int&c)
{
	if (*this < c)
	{
		*this = 0;
		cerr << "Вычитаемое больше уменьшаемого!" << endl;
		return *this;
	}
	data[number-3] = data[number-3] - (c - (c % 100000000));
	if (data[number-3] < 0)
	{
		data[number-3] += 10000;
		data[number-4]--;
	}
	data[number-2] = data[number-2] - (c - (c % 10000) - (c % 100000000));
	if (data[number-2] < 0)
	{
		data[number-2] += 10000;
		data[number-3]--;
	}
	data[number-1] = data[number-1] - (c % 10000);
	if (data[number-1] < 0)
	{
		data[number-1] += 10000;
		data[number-2]--;
	}
	return *this;
}
BigInt BigInt::operator += (const int&c)
{
	
	data[number-3] = data[number-3] + (c - (c % 100000000));
	if (data[number-3] > 9999)
	{
		data[number-3] -= 10000;
        data[number-4]++;
	}
	data[number-2] = data[number-2] + (c - (c % 10000) - (c % 100000000));
	if (data[number-2] > 9999)
	{
		data[number-2] -= 10000;
		data[number-3]++;
	}
	data[number-1] = data[number-1] + (c % 10000);
	if (data[number-1] > 9999)
	{
		data[number-1] -= 10000;
		data[number-2]++;
	}
	return *this;
}
BigInt BigInt::operator -= (const int&c)
{
	if (*this < c)
	{
		*this = 0;
		cerr << "Вычитаемое больше уменьшаемого!" << endl;
		return *this;
	}
	data[number-3] = data[number-3] - (c - (c % 100000000));
	if (data[number-3] < 0)
	{
		data[number-3] += 10000;
		data[number-4]--;
	}
	data[number-2] = data[number-2] - (c - (c % 10000) - (c % 100000000));
	if (data[number-2] < 0)
	{
		data[number-2] += 10000;
		data[number-3]--;
	}
	data[number-1] = data[number-1] - (c % 10000);
	if (data[number-1] < 0)
	{
		data[number-1] += 10000;
		data[number-2]--;
	}
	return *this;
}
BigInt BigInt::operator = (BigInt&c)
{
	if (this == &c)
	{
		return *this;
	}
	for (int i = 0; i < number; i++)
	{
		data[i] = c.data[i];
	}
	return *this;
}
BigInt BigInt::operator = (int&c)
{
	for (int i = 0; i < number; i++)
	{
		data[i] = 0;
	}
	data[number-3] = (c - (c % 100000000));
	data[number-2] = (c - (c % 10000) - (c - (c % 100000000)));
	data[number-1] = (c % 10000);
	return *this;
}
bool BigInt::operator == (BigInt&c)const
{
	for (int i = 0; i < number; i++)
	{
		if (data[i] != c.data[i])
		{
			return false;
		}
	}
	return true;
}
bool BigInt::operator != (BigInt&c)const
{
	for (int i = 0; i < number; i++)
	{
		if (data[i] != c.data[i])
		{
			return true;
		}
	}
	return false;
}
bool BigInt::operator >= (BigInt&c)const
{
	for (int i = 0; i < number; i++)
	{
		if (data[i] < c.data[i])
		{
			return false;
		}
	}
	return true;
}
bool BigInt::operator <= (BigInt&c)const
{
	
		for (int i = 0; i < number; i++)
		{
			if (data[i] > c.data[i])
			{
				return false;
			}
		}
		return true;
	
}
bool BigInt::operator > (BigInt&c)const
{
	for (int i = 0; i < number; i++)
	{
		if (data[i] < c.data[i])
		{
			return false;
		}
	}
	if (*this == c)
	{
		return false;
	}
	return true;
}
bool BigInt::operator < (BigInt&c)const
{
	for (int i = 0; i < number; i++)
	{
		if (data[i] > c.data[i])
		{
			return false;
		}
	}
	if (*this == c)
	{
		return false;
	}
	return true;
}
bool BigInt::operator == (int&c)const
{
	for (int i = 0; i < number-3; i++)
	{
		if (data[i] != 0)
			return false;
	}
	if (data[number-3] != (c - (c % 100000000)))
		return false;
	if (data[number-2] != (c - (c % 10000) - c + (c % 100000000)))
		return false;
	if (data[number-1] != (c % 10000))
		return false;
	return true;
}
bool BigInt::operator != (int&c)const
{
	
		for (int i = 0; i < number-3; i++)
		{
			if (data[i] != 0)
				return true;
		}
		if ((data[number-3] != (c - (c % 100000000))) && (data[number-2] != (c - (c % 10000) - c + (c % 100000000))) && (data[number-1] != (c % 10000)))
			return true;
		return false;
}
bool BigInt::operator >= (int&c)const
{
	for (int i = 0; i < number-3; i++)
	{
		if (data[i] != 0)
			return true;
	}
	if (data[number-3] < (c - (c % 100000000)))
		return false;
	if (data[number-2] < (c - (c % 10000) - c + (c % 100000000)))
		return false;
	if (data[number-1] < (c % 10000))
		return false;
	return true;
}
bool BigInt::operator <= (int&c)const
{
	for (int i = 0; i < number-3; i++)
	{
		if (data[i] != 0)
			return false;
	}
	if (data[number-3] > (c - (c % 100000000)))
		return false;
	if (data[number-2] > (c - (c % 10000) - c + (c % 100000000)))
		return false;
	if (data[number-1] > (c % 10000))
		return false;
	return true;
}
bool BigInt::operator > (int&c)const
{
	for (int i = 0; i < number-1; i++)
	{
		if (data[i] != 0)
			return true;
	}
	if (data[number-3] < (c - (c % 100000000)))
		return false;
	if (data[number-2] < (c - (c % 10000) - c + (c % 100000000)))
		return false;
	if (data[number-1] < (c % 10000))
		return false;
	if (*this == c)
		return false;
	return true;
}
bool BigInt::operator < (int&c)const
{
	for (int i = 0; i < number-3; i++)
	{
		if (data[i] != 0)
			return false;
	}
	if (data[number-3] > (c - (c % 100000000)))
		return false;
	if (data[number-2] > (c - (c % 10000) - (c - (c % 100000000))))
		return false;
	if (data[number-1] > (c % 10000))
		return false;
	if (*this == c)
		return false;
	return true;
}
bool BigInt::operator == (const int&c)const
{
	for (int i = 0; i < number-3; i++)
	{
		if (data[i] != 0)
			return false;
	}
	if (data[number-3] != (c - (c % 100000000)))
		return false;
	if (data[number-2] != (c - (c % 10000) -c + (c % 100000000)))
		return false;
	if (data[number-1] != (c % 10000))
		return false;
	return true;
}
bool BigInt::operator != (const int&c)const
{

	for (int i = 0; i < number-3; i++)
	{
		if (data[i] != 0)
			return false;
	}
	if ((data[number-3] != (c - (c % 100000000))) && (data[number-2] != (c - (c % 10000) - c + (c % 100000000))) && (data[number-1] != (c % 10000)))
		return true;
	return false;
}
bool BigInt::operator >= (const int&c)const
{
	for (int i = 0; i < number-3; i++)
	{
		if (data[i] != 0)
			return false;
	}
	if (data[number-3] < (c - (c % 100000000)))
		return false;
	if (data[number-2] < (c - (c % 10000) - c + (c % 100000000)))
		return false;
	if (data[number-1] < (c % 10000))
		return false;
	return true;
}
bool BigInt::operator <= (const int&c)const
{
	for (int i = 0; i < number-3; i++)
	{
		if (data[i] != 0)
			return true;
	}
	if (data[number-3] >(c - (c % 100000000)))
		return false;
	if (data[number-2] > (c - (c % 10000) - c + (c % 100000000)))
		return false;
	if (data[number-1] > (c % 10000))
		return false;
	return true;
}
bool BigInt::operator > (const int&c)const
{
	for (int i = 0; i < number-3; i++)
	{
		if (data[i] != 0)
			return true;
	}
	if (data[number-3] < (c - (c % 100000000)))
		return false;
	if (data[number-2] < (c - (c % 10000) - c + (c % 100000000)))
		return false;
	if (data[number-1] < (c % 10000))
		return false;
	if (*this == c)
		return false;
	return true;
}
bool BigInt::operator < (const int&c)const
{
	for (int i = 0; i < number-3; i++)
	{
		if (data[i] != 0)
			return false;
	}
	if (data[number-3] >(c - (c % 100000000)))
		return false;
	if (data[number-2] > (c - (c % 10000) - (c - (c % 100000000))))
		return false;
	if (data[number-1] > (c % 10000))
		return false;
	if (*this == c)
		return false;
	return true;
}
BigInt BigInt::operator ++ ()
{
	data[number-1]++;
	if (data[number-1] > 9999)
	{
		data[number-2]++;
		data[number-1] -= 10000;
	}
	return *this;
}
BigInt BigInt::operator -- ()
{
	if (*this < 0)
	{
		*this = 0;
		cerr << "Вычитаемое больше уменьшаемого!" << endl;
		return *this;
	}
	data[number-1]--;
	if (data[number-1] < 0)
	{
		data[number-2]--;
		data[number-1] += 10000;
	}
	return *this;
}
BigInt BigInt::operator ++ (int)
{
	data[number - 1]++;
	if (data[number - 1] > 9999)
	{
		data[number - 2]++;
		data[number - 1] -= 10000;
	}
	return *this;
}
BigInt BigInt::operator -- (int)
{
	if (*this < 0)
	{
		*this = 0;
		cerr << "Вычитаемое больше уменьшаемого!" << endl;
		return *this;
	}
	data[number - 1]--;
	if (data[number - 1] < 0)
	{
		data[number - 2]--;
		data[number - 1] += 10000;
	}
	return *this;
}
BigInt BigInt::operator = (const int&c)
{
	for (int i = 0; i < number; i++)
	{
		data[i] = 0;
	}
	data[number-3] = (c - (c % 100000000));
	data[number-2] = (c - (c % 10000) - (c -(c % 100000000)));
	data[number-1] = (c % 10000);
	return *this;
}