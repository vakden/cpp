#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct company
{
	string num;
	string name;
	company* up = NULL;
	company* down = NULL;
	void input(string temp)
	{
		int nachalo, konec;
		nachalo = temp.find_first_not_of(" ", 0);
		konec = temp.find_first_of(" ", nachalo);
		num = temp.substr(nachalo, konec - nachalo);
		nachalo = temp.find_first_not_of(" ", konec);
		name = temp.substr(nachalo, temp.length()-nachalo);
	}
};
class list
{
public:
	company* first;
	company* last;
	list() :first(NULL),last(NULL) {};
	void add(company b)
	{
		company* temp;
		temp = new company;
		company* temp1;
		temp1 = new company;
		temp1->num = b.num;
		temp1->name = b.name;
		if (last == NULL)
		{
			last = temp1;
		}
		if (first == NULL)
		{
			first = temp1;
		}
		else
		{
			temp->down = first;
			while (temp != NULL)
			{
				if (temp1->name > temp->name)
				{
					temp = temp->down;
				}
				else
				{
					break;
				}
			}
			if (temp != NULL)
			{
				temp1->down = temp;
				if (temp->up != NULL)
				{
					temp1->up = temp->up;
					(temp->up)->down = temp1;
					temp->up = temp1;
				}
				else
				{
					temp1->up = NULL;
					first = temp1;
					temp->up = temp1;
					temp1->down = temp;
				}
			}
			else
			{
				temp1->down = NULL;
				temp = last;
				temp->down = temp1;
				temp1->up = temp;
				last = temp1;
			}
		}
	}
	void show_down()
	{
		company* temp = first;
		while (temp != NULL)
		{
			cout << temp->num << " ";
			cout << temp->name << endl;
			temp = temp->down;
		}
		cout << endl;
	}
	void show_up()
	{
		company* temp = last;
		while (temp != NULL)
		{
			cout << temp->num << " ";
			cout << temp->name << endl;
			temp = temp->up;
		}
		cout << endl;
	}
	~list(){}
};

class list1
{
public:
	company* first;
	list1() :first(NULL) {};
	void add(company b)
	{
		company* temp;
		temp = new company;
		temp->down = first;
		temp->num = b.num;
		temp->name = b.name;
		first = temp;
	}
	void show()
	{
		company* temp = first;
		while (temp != NULL)
		{
			cout << temp->num << " ";
			cout << temp->name << endl;
			temp = temp->down;
		}
		cout << endl;
	}
	~list1() {}
};

int main()
{
	setlocale(LC_ALL, "rus");
	list a;
	list1 d;
	setlocale(LC_ALL, "rus");
	ifstream in;
	string temp;
	company b;
	in.open("Text.txt");
	if(!in.is_open())
	{
		cout << "Не удалось открыть файл!" << endl;
		system("pause");
		return 0;
	}
	getline(in, temp);
	if (temp == "")
	{
		cout << "Файл пуст!" << endl;
		system("pause");
		return 0;
	}
	do
	{
		b.input(temp);
		a.add(b);
	} while (getline(in, temp));
	cout << "Список в алфавитном порядке: " << endl;
	a.show_down();
	cout << "Список в антиалфавитном порядке: " << endl;
	a.show_up();
	company* c = a.last;
	while (c != NULL)
	{
		if(c->num.length() == 3)
		{
			d.add(*c);
		}
		c = c->up;
	}
	cout << "Спецслужбы: " << endl;
	d.show();
	system("pause");
	return 0;
}