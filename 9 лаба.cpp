#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#pragma warning (disable : 4996)

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int k;
	string razdel;
	cout << "Введите символы-разделители: " << endl;
	getline(cin, razdel);
	if (razdel == "")
	{
		cout << "Разделителей нет!" << endl;
		system("pause");
		return 0;
	}
	razdel += '\n';
	cout << "Введите число К:" << endl;
	cin >> k;
	ifstream in;
	ofstream out;
	string str;
	in.open("input.txt");
	getline(in, str);
	if (!in.is_open())
	{
		cout << "Файл не удалось открыть" << endl;
		return 1;
	}
	string leks[10000];
	string slovo;
	int sch[10000];
	for (int i = 0; i < 10000; i++)
	{
		sch[i] = 1;
	}
	int n = 0;
	if (str == "")
	{
		cout << "Файл пуст!" << endl;
		system("pause");
		return 0;
	}
	do
	{
        for (int i = 0; i < str.length(); i++)
		{
			str[i] = toupper(str[i]);
		}
		int nachalo = 0, konec = 0;
		while ((nachalo = str.find_first_not_of(razdel, nachalo)) != -1)
		{
			konec = str.find_first_of(razdel, nachalo);
			if (konec == -1)
			{
				konec = str.length();
			}
			slovo = str.substr(nachalo, konec - nachalo);
			int i = 0;
			int c = 0;
			for (; i <= n; i++)
			{
				if (slovo == leks[i])
				{
					c++;
					break;
				}
			}
			if (c == 1)
			{
				sch[i]++;
				str.erase(nachalo, konec - nachalo);
			}
			else
			{
				leks[n] = slovo;
				n++;
				nachalo = konec;
			}
		}
	} while (getline(in, str));
	in.close();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (sch[j] < sch[j + 1])
			{
				swap(sch[j], sch[j + 1]);
				swap(leks[j], leks[j + 1]);
			}
		}
	}
	out.open("output.txt");
	if (!out.is_open())
	{
		cout << "Файл не удалось открыть" << endl;
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (sch[i] > k)
		{
			out << leks[i] << "\t" << sch[i] << endl;
		}
		if (sch[i] == k)
		{
			out << leks[i] << "\t" << sch[i] << endl;
		}
	}
	out.close();
	system("pause");
	return 0;
}
