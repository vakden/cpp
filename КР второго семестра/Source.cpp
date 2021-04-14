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
			throw "Ошибка открытия файла выхода";
		}
		in.open("Input.txt");
		if (!in)
		{
			throw "Ошибка открытия входного файла";
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
		out << "Задание 1" << endl;
		out << "Разместить данные в последовательном контейнере deque" << endl;
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
		out << "Выполнить сортировку по номеру клумбы" << endl;
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
		cout << "Введите форму клумбы: " << endl;
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
		out << "Задание 2" << endl;
		out << "Вывести список всех видов цветов, растущих на клумбах указанной формы(" << form << ')' << endl;
		for_each(mySet.begin(), mySet.end(), [&](string a) {out << a << endl; });
		if (sch == 0)
		{
			out << "Таких клумб нет или на таких клумбах нет цветов" << endl;
		}
		int num;
		cout << "Введите количество цветов на клумбе:" << endl;
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
		out << "Найти клумбы с указанным количеством цветков(" <<num<< ')' << endl;
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
			out << "Клумб с указанным числом цветков нет" << endl;
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