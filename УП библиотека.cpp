#include <iostream>
#include <string>

using namespace std;

struct book
{
	int udk;                         //Номер УДК
	string name;                          //Название
	string autor;                      //Автор
	int data;                                //Дата
	int kol;                        //Количество в библиотеке
	void Input(book &book);           //Функция ввода данных в структуру
	book *Next;                          //Адрес на следующий элемент
};

class List
{       
public:
	book *Head;
	List() :Head(NULL) {};                                                
	void Add(book &book);           
	void Show();                           
};


void book::Input(book &boo)
{
	cout << endl;
		cout << "Введите номер УДК: ";
		cin >> udk;
	
		cin.ignore();
	    cout << "Введите название книги: ";
        getline(cin,name);
	    cout << "Введите имя автора: ";
	    getline(cin, autor);
		
	    
		cout << "Год написания: ";
		cin >> data;

		cout << "Введите количество книг: ";
		cin >> kol;
		
	system("cls");
}


/*ФУНКЦИЯ ДОБАВЛЕНИЯ НОВОЙ СТРУКТУРЫ В СПИСОК*/
void List::Add(book &boo)
{
	book *temp = new book;          
	temp->Next = Head;                     

	temp->udk = boo.udk;									 
	temp->name = boo.name;
	temp->autor = boo.autor;
	temp->data = boo.data;
	temp->kol = boo.kol;

	Head = temp;                           
}



void List::Show()
{
	book *temp = Head;                 

	while (temp != NULL)                   
	{
		
		cout << "\t\t\t" << temp->udk << "\t\t";
		cout << temp->name << "\t\t";      
		cout << temp->autor << "\t\t";   
		cout << temp->data << "\t\t";      
		cout << temp->kol << endl;      
      	temp = temp->Next;                 
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	book boo;                        
	int N;                                   
	List lst;                                 
	book *temp = lst.Head;
	cout << "Введите количество книг в библиотеке: ";
	cin >> N;
	if(N == 0)
	{
		cout << "Библиотека пустая!" << endl;
		system("pause");
		return 0;
	}
	if (N < 0)
	{
		cout << "Нехороший вы человек, Валентина Владимировна. Количество книг в библиотеке должно быть натуральным числом! =)" << endl;
		system("pause");
		return 0;
	}
	system("cls");

	for (int i = 0; i<N; i++)
	{
		int c = 0;
		boo.Input(boo);
		book *temp = lst.Head;
		while (temp != NULL)                   
		{
			if (temp -> udk == boo.udk)
			{
				c++;
			}
			temp = temp->Next;                 
		}
		if (c > 0)
		{
			cout << "Такой УДК уже существует! Повторите ввод данных!" << endl;
			i--;
		}
		else
		{ 
			lst.Add(boo);
			cout << "Новая книга добавлена в библиотеку!" << endl;
		}
	}
	system("pause");

	int vib = 1;
	while (vib != 0)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t\tВыберите действие: \n\t\t\t\tВзять книгу - 1; \n\t\t\t\tВернуть книгу - 2; \n\t\t\t\tПросмотреть данные библиотеки - 3; \n\t\t\t\tВыход - 0;" << endl;
		cout << "\n\t\t\t\t";
		cin >> vib;
		
		if (vib == 1)
		{
			int c = 0;
			int udk;
			system("cls");
			cout << "\n\n\n\n\n\n\t\t\t\tВведите УДК желаемой книги: ";
			cin >> udk;
			book *temp = lst.Head;
			while (temp != NULL)                  
			{
				if (temp->udk == udk)
				{
					c++;
					break;
				}
				temp = temp->Next;                
			}
			if (c > 0)
			{
				if (temp->kol > 0)
				{
					temp->kol -= 1;
					cout << "\n\t\t\t\tКнига выдана!\n\n\n\n\n";
				}
				if (temp->kol == 0)
				{
					cout << "\n\t\t\t\tЭтой книги нет в наличии!\n\n\n\n\n";
				}
			}
			else
			{
				
				cout << "\n\t\t\t\tВ библиотеке книги с таким УДК нет!\n\n\n\n\n" << endl;
			}
			system("pause");
		}
		if (vib == 2)
		{
			int c = 0;
			int udk;
			system("cls");
			cout << "\n\n\n\n\n\n\t\t\t\tВведите УДК книги, которую хотите вернуть: ";
			cin >> udk;
			book *temp = lst.Head;
			while (temp != NULL)                 
			{
				if (temp->udk == udk)
				{
					c++;
					break;
				}
				temp = temp->Next;                
			}
			if (c > 0)
			{
				
					temp->kol += 1;
					cout << "\n\t\t\t\tКнига возвращена!\n\n\n\n\n";
				
			}
			else
			{
				cout << "\n\t\t\t\tВ библиотеке книги с таким УДК не числились!\n\n\n\n\n" << endl;
			}
			system("pause");
		}
		if (vib == 3)
		{
			system("cls");
			cout << "\n\t\t\t\t\tСписок: " << endl;
			lst.Show();
			cout << "\n\n\n\n\n" << endl;
			system("pause");
		}
	}
	system("cls");
	cout << "\n\n\n\n\n\n\t\t\t\tДо свидания! =)\n\n\n\n"<< endl;
	system("pause");
	return 0;
}