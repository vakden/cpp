#include <cstring>
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");
	string str, slovo;
	int nachalo = 0, konec = 0, kolv = 0, j = 0, leks, k = 0;
	cout << "Ââåäèòå ñòðîêó:" << endl;
	getline(cin, str);
	while (str[0] == ' ')
	{
		str.erase(0, 1);
	}
	if (str.find_first_not_of(' ', nachalo) == -1 || str.empty())
	{
		cout << "Âàøà ñòðîêà ïóñòàÿ èëè ñîñòîèò òîëüêî èç ðàçäåëèòåëåé!" << endl;;
		system("pause");
		return 0;
	}


	while ((nachalo = str.find_first_not_of(' ', nachalo)) != -1)
	{
		konec = str.find_first_of(' ', nachalo + 1);
		if (konec == -1)
		{
			konec = str.length();
		}
		kolv++;
		nachalo = konec;
	}


	nachalo = 0;
	string *sarr = new string[kolv];
	while ((nachalo = str.find_first_not_of(' ', nachalo)) != -1)
	{
		konec = str.find_first_of(' ', nachalo);
		if (konec == -1)
		{
			konec = str.length();
		}
		slovo = str.substr(nachalo, konec - nachalo);
		for (int i = 0; i < slovo.length(); i++, k++)
		{
			if (slovo[i] < 65 || (slovo[i] > 90 && slovo[i] < 97) || slovo[i]>122)
			break;
		}
		if (k == slovo.length())
		{
			sarr[j] = slovo;
			j++;
		}
		k = 0;
		nachalo = konec;
	}


	for (int i = 0; i < j - 1; i++)
	{
		for (int k = 0; k < j - i - 1; k++)
		{
			if (strcmp(sarr[k].c_str(), sarr[k + 1].c_str()) > 0)
			{
				swap(sarr[k], sarr[k + 1]);
			}
		}
	}

	leks = 0;
	nachalo = 0;
	while ((nachalo = str.find_first_not_of(' ', nachalo)) != -1)
	{
		konec = str.find_first_of(' ', nachalo);
		if (konec == -1)
		{
			konec = str.length();
		}
		slovo = str.substr(nachalo, konec - nachalo);
		for (int i = 0; i < slovo.length(); i++, k++)
		{
			if (slovo[i] < 65 || (slovo[i] > 90 && slovo[i] < 97) || slovo[i]>122)
				break;
		}
		if (k == slovo.length() && slovo != sarr[leks])
		{
			str.erase(nachalo, konec - nachalo);
			str.insert(nachalo, sarr[leks]);
			nachalo = konec - slovo.length() + sarr[leks].length();
			leks++;
		}
		else
			if (k == slovo.length() && slovo == sarr[leks])
			{
				leks++;
				nachalo = konec;
			}
			else
				nachalo = konec;
		k = 0;
	}

	cout << "Ïðåîáðàçîâàííàÿ ñòðîêà: " << endl;
	cout << str << endl;
	delete[] sarr;
	system("pause");
}
