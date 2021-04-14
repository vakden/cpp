#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool proverka_ch (string leks)
{
	string cif = "1234567890";
	if (leks.find_first_not_of(cif, 0) == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}



bool proverka_p (string leks)
{
	int temp = atoi(leks.c_str());
	int pmet = 0, el = 0;
	while (temp != 0)
	{
		el = temp % 10;
		temp /= 10;
		pmet = 10 * pmet + el;
	}
	if (pmet == atoi(leks.c_str()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	if (!in.is_open())
	{
		cout << "Не удалось открыть файл!" << endl;
		system("pause");
		return 1;
	}
	string razdel, str, leks;
	getline(in, razdel);
	if (razdel == "")
	{
		cout << "Файл пуст!" << endl;
		system("pause");
		return 1;
	}
	int nachalo = 1;
	while (getline(in,str))
	{
		if ((str == "") && (nachalo == 1))
		{
			cout << "В файлк отстуствует текст!" << endl;
			system("pause");
			return 1;
		}
		int nachalo = 0, konec = 0;
		while ((nachalo = str.find_first_not_of( razdel, konec)) != -1)
		{
			konec = str.find_first_of(razdel, nachalo);
			if (konec == -1)
			{
				konec = str.length();
			}
			leks = str.substr(nachalo, konec - nachalo);
			nachalo = konec;
			if (proverka_ch(leks))
			{
				out << leks << "->";
				if (proverka_p(leks))
				{
					out << "да; ";
				}
				else
				{
					out << "нет; ";
				}
			}
		}
	}
    return 0;
}