#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include "Header.h"
#include <vector>
#include <fstream>
#include <set>

using namespace std;

string MyTranslate(string s) 
{
	string x;
	x = s;
	for (unsigned i = 0; i<x.length(); i++)
		if ((x[i] >= -128) && (x[i] <= -81))
			x[i] += 64;
		else
			if ((x[i] >= -32) && (x[i] <= -17))
				x[i] += 16;
	return x;
}

void input(string str, deque<clumba> *b)
{
	clumba a;
	string data;
		int nachalo = 0;
		int konec = 0;
		nachalo = str.find_first_not_of( '/', konec);
		konec = str.find_first_of( '/', nachalo);
		a.num = atoi(str.substr(nachalo, konec - nachalo).c_str());
		nachalo = str.find_first_not_of('/', konec);
		konec = str.find_first_of('/', nachalo);
		a.form = str.substr(nachalo, konec - nachalo);
		while (konec != str.size())
		{
			nachalo = str.find_first_not_of('/', konec);
			konec = str.find_first_of('/', nachalo);
			if (konec == -1)
			{
				konec = str.size();
			}
			data = str.substr(nachalo, konec - nachalo);
			a.flowers.push_back(data);
		}
		b->push_back(a);
}
	
int main()
{
	try
	{
		setlocale(LC_ALL, "rus");
		deque<clumba> myDeq;
		ifstream in;
		ofstream out;
		int sch;
		out.open("ANSWER18.txt");
		if (!out)
		{
			throw "������ �������� ����� ������";
		}
		in.open("Input.txt");
		if (!in)
		{
			throw "������ �������� �������� �����";
		}
		string str;
		getline(in, str);
		if (str.size() == 0)
		{
			throw "File is empty!";
		}
		do
		{
			input(str, &myDeq);
		} while (getline(in, str));
		in.close();
		out << "������� 1" << endl;
		out << "���������� ������ � ���������������� ���������� deque" << endl;
		for_each(myDeq.begin(), myDeq.end(), [&](clumba a)
		{
			out << a.num << '/' << a.form;
			for (auto &v : a.flowers)
			{
				out << '/' << v;
			}
			out << endl;
		});
		sort(myDeq.begin(), myDeq.end(), [&](clumba a, clumba b)
		{
			return a.num < b.num;
		});
		out << "��������� ���������� �� ������ ������" << endl;
		for_each(myDeq.begin(), myDeq.end(), [&](clumba a)
		{
			out << a.num << '/' << a.form;
			for (auto &v : a.flowers)
			{
				out << '/' << v;
			}
			out << endl;
		});
		set<string> mySet;
		string form;
		cout << "������� ����� ������: " << endl;
		cin >> form;
		form = MyTranslate(form);
		sch = 0;
		for_each(myDeq.begin(), myDeq.end(), [&](clumba a)
		{
			if (a.form == form)
			{
				sch++;
				for (auto &v : a.flowers)
				{
					mySet.emplace(v);
				}
			}
		});
		out << "������� 2" << endl;
		out << "������� ������ ���� ����� ������, �������� �� ������� ��������� �����(" << form << ')' << endl;
		for_each(mySet.begin(), mySet.end(), [&](string a) {out << a << endl; });
		if (sch == 0)
		{
			out << "����� ����� ��� ��� �� ����� ������� ��� ������" << endl;
		}
		int num;
		cout << "������� ���������� ������ �� ������:" << endl;
		cin >> num;
		vector<clumba> myVec;

		sch = 0;
		for_each(myDeq.begin(), myDeq.end(), [&](clumba a)
		{
			if ((a.flowers).size() == num)
			{
				myVec.push_back(a);
				sch++;
			}
		});
		out << "����� ������ � ��������� ����������� �������(" <<num<< ')' << endl;
		for_each(myVec.begin(), myVec.end(), [&](clumba a)
		{
			out << a.num << '/' << a.form;
			for (auto &v : a.flowers)
			{
				out << '/' << v;
			}
			out << endl;
		});
		if (sch == 0)
		{
			out << "����� � ��������� ������ ������� ���" << endl;
		}
		out.close();
		system("pause");
		return 0;
	}
	catch(char* err)
	{
		cerr << err << endl;
	}
}