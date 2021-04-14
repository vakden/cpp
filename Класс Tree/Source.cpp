#define _CRT_SECURE_NO_WARNINGS
#include "class.h"
#include <iostream>

using namespace std;

FILE *in, *out;


void Print(int & a)
{
	fprintf(out, "%i\n", a);
}

void PrintStart()
{
	fprintf(out, "Список элементов:\n");
}

int find(char * str)
{
	char * nstr;
	char * token = strtok(str, " \n");
	while (token != NULL)
	{
		int a = strtol(token, &nstr, 10);
		if (!strlen(nstr))
		{
			return a;
		}
		token = strtok(NULL, " \n");
	}
	return 0;
}

Tree a;

void man(char in, char * str)
{

	if (in != 'I' && in != 'D' && in != 'L' && in != 'F')
		return;
	switch (in)
	{
	case 'I':
	{
		int val = find(str);
		if (!(val < 0))
		{
			int rval = val;
			if (a.Add(rval))
				fprintf(out, "%i:Вставлено.\n\n", rval);
			else
				fprintf(out, "%i: Не вставлено.\n\n", rval);
			break;
		}
		else
			fprintf(out, "Некорректный ввод.\n\n");
		break;
	}
	case 'D':
	{
		int val = find(str);
		int rval = val;
		if (!a.RootCheck())
		{
			fprintf(out, "%i: Дерево пустое.\n\n", rval);
			break;
		}
		if (val != 2)
		{
			if (a.Remove(rval))
				fprintf(out, "%i: Удалено.\n\n", rval);
			else
				fprintf(out, "%i: Не удалено.\n\n", rval);
			break;
		}
		else
		{
			fprintf(out, "Некорректный ввод.\n\n");
			break;
		}
	}

	case 'L':
	{
		if (a.RootCheck())
		{
			PrintStart();
			a.walk(Print);
			fprintf(out, "\n");
		}
		else
			fprintf(out, "Дерево пустое.\n\n");
		break;
	}

	case 'F':
	{
		int val = find(str);
		int rval = val;
		if (!a.RootCheck())
		{
			fprintf(out, "%i: Дерево пустое.\n\n", rval);
			break;
		}
		if (val != 2)
		{
			int t = 0;
			if (a.FindByValue(rval, t))
			{
				fprintf(out, "%i: ", rval);
				fprintf(out, "Найдено после %i сравнений(ия).\n\n", t);
			}
			else
			{
				fprintf(out, "%i: ", rval);
				fprintf(out, "Не найдено после %i сравнений(ия).\n\n", t);
			}
			break;
		}
		else
		{
			fprintf(out, "Некорректный ввод.\n\n");
			break;
		}
	}
	}
}



int main()
{
	setlocale(LC_ALL, "rus");
	try {

		const int N = 100;
		if (!(in = fopen("input.txt", "r")))
			throw "Входной файл не открыт";
		if (!(out = fopen("output.txt", "w")))
			throw "Выходной файл не открыт";
		char cur_str[N];
		if (fgets(cur_str, N - 1, in) == NULL)
			throw "Файл пустой";
		fgets(cur_str, N - 1, in);
		do
		{
			char check = cur_str[0];
			man(check, cur_str);
			fgets(cur_str, N - 1, in);
		} while (!feof(in));

		//2
		Tree b1;
		b1 = a;

		
		//3
		Tree b2(a);

	}
	catch (char *th)
	{
		cout << th << endl;
	}
	return 0;
}