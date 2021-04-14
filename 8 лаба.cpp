#include <iostream>
#include <string.h>
#include <string>
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
	FILE* in;
	FILE* out;
	char text[100];
	string str;
	in = fopen("input.txt", "r");
	if (in == NULL)
	{
		cout << "Файл не удалось открыть" << endl;
		return 1;
	}
	string leks[10000];
	string slovo;
	int sch[2500];
	for (int i = 0; i < 2500; i++)
	{
		sch[i] = 1;
	}
	int n = 0;
	fgets(text, 100, in);
	if (text == "")
	{
		cout << "Файл пуст!" << endl;
		system("pause");
		return 0;
	}
	do
	{
		for (int i = 0; i < strlen(text); i++)
		{
			text[i] = toupper(text[i]);
		}
		str = text;
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
	}
	while (fgets(text, 100, in));
	fclose(in);
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (sch[j] > sch[j + 1])
			{
				swap(sch[j], sch[j + 1]);
				swap(leks[j], leks[j + 1]);
			}
		}
	}
	out = fopen("output.txt", "w");
	if (out == NULL)
	{
		cout << "Файл не удалось открыть" << endl;
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (sch[i] > k)
		{
			fputs(leks[i].c_str(), in);
			fputs("\t", in);
			fprintf(in, "%d\t", sch[i]);
			fputs("\n", in);
		}
		if (sch[i] == k)
		{
			fputs(leks[i].c_str(), in);
			fputs("\t", in);
			fprintf(in, "%d", sch[i]);
			fputs("\n", in);
		}
	}
	fclose(out);
	system("pause");
	return 0;
}
