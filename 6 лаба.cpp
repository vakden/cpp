#include <stdio.h>
#include <iostream>
#include <string.h>
#pragma warning(disable : 4996)

using namespace std;

void rew(char* lek)
{

		for (int i = 0; i < strlen(lek) / 2; i++)
		{
			swap(lek[i], lek[(strlen(lek)) - 1 - i]);
		}
}

bool chislo(char* lek)
{
	int size1, size2=0, chislo;
	size1 = strlen(lek);
	chislo = atoi(lek);
	if ((chislo == 0) && (lek == "0")) return false;
	while (chislo != 0)
	{
		chislo /= 10;
		size2++;
	}
	if (size1 == size2) return true;
}
 
bool slovo(char* lek)
{
	char sim[11] = "1234567890";
	for (int j = 0; j <= strlen(lek); j++)
	{
		for (int m = 0; m <= 11; m++)
		{
			if (lek[j] == sim[m]) { break; return false; }
		}
	}
	int c = 0;
	for (int j = 0; j <= strlen(lek); j++)
	{
		for (int m = 0; m <= 11; m++)
		{
			if (lek[j] == sim[m]) { c++; }
		}
	}
	if (c == 1) { return true; }
}

void top(char*lek)
{
	char sim;
	for (int i = 0; i < strlen(lek); i++)
	{
		sim = lek[i];
		sim = toupper(sim);
		lek[i] = sim;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	char* str;
	str = new char[301];
	char sim[63] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
	cout << "Введите строку длиной не более 300 символов, состоящую из букв латинского алфавита и цифр (остальные символы будут считаться разделителями): " << endl;
	cin.get(str,301);
	if (strlen(str) > 301)
	{
		cout << "Выход за границы строки!" << endl;
		system("pause");
		return 0;
	}
	for (int i = 0; i < strlen(str); i++)
	{
		int c = 0;
		for (int j = 0; j <= 62; j++)
		{
			if (str[i] == sim[j]) c++;
		}
		if (c == 0) str[i] = ' ';
	}
	int c = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j <= 62; j++)
		{
			if (str[i] == sim[j]) c++;
		}
	}
	if (strlen(str) == 0) 
	{  
		cout << "Строка пуста!" << endl;
		system("pause");
		return 0;
	}
	if (c == 0)
	{
		cout << "Строка состоит только из разделителей!" << endl;
		system("pause");
		return 0;
	}

	char *p = strtok(str, " ");
	char *leks[150];
	int k = 0;
	while (p != NULL)
	{
		leks[k] = p;
		p = strtok(NULL, " ");
		k++;
	}
	for (int i = 0; i < k; i++)
	{
		if (strlen(leks[i]) < 7) rew(leks[i]);
		else  if (chislo(leks[i]) == 1) rew(leks[i]);
	}
	for (int i = 0; i < k; i++)
	{
		if (slovo(leks[i]) == 1) top(leks[i]);
	}
	char* s = new char [301];
	strcpy(s,"\0");
	for (int i = 0; i < k; i++)
	{
		strcpy(s , strcat(s, leks[i]));
		s = strcat(s, " ");
	}
	cout << "Ваша новая строка: " << endl;
	cout << s << endl;

	system("pause");
}