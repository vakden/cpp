#include <iostream>
#include <string>

using namespace std;

struct book
{
	int udk;                         //����� ���
	string name;                          //��������
	string autor;                      //�����
	int data;                                //����
	int kol;                        //���������� � ����������
	void Input(book &book);           //������� ����� ������ � ���������
	book *Next;                          //����� �� ��������� �������
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
		cout << "������� ����� ���: ";
		cin >> udk;
	
		cin.ignore();
	    cout << "������� �������� �����: ";
        getline(cin,name);
	    cout << "������� ��� ������: ";
	    getline(cin, autor);
		
	    
		cout << "��� ���������: ";
		cin >> data;

		cout << "������� ���������� ����: ";
		cin >> kol;
		
	system("cls");
}


/*������� ���������� ����� ��������� � ������*/
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
	cout << "������� ���������� ���� � ����������: ";
	cin >> N;
	if(N == 0)
	{
		cout << "���������� ������!" << endl;
		system("pause");
		return 0;
	}
	if (N < 0)
	{
		cout << "��������� �� �������, ��������� ������������. ���������� ���� � ���������� ������ ���� ����������� ������! =)" << endl;
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
			cout << "����� ��� ��� ����������! ��������� ���� ������!" << endl;
			i--;
		}
		else
		{ 
			lst.Add(boo);
			cout << "����� ����� ��������� � ����������!" << endl;
		}
	}
	system("pause");

	int vib = 1;
	while (vib != 0)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t\t�������� ��������: \n\t\t\t\t����� ����� - 1; \n\t\t\t\t������� ����� - 2; \n\t\t\t\t����������� ������ ���������� - 3; \n\t\t\t\t����� - 0;" << endl;
		cout << "\n\t\t\t\t";
		cin >> vib;
		
		if (vib == 1)
		{
			int c = 0;
			int udk;
			system("cls");
			cout << "\n\n\n\n\n\n\t\t\t\t������� ��� �������� �����: ";
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
					cout << "\n\t\t\t\t����� ������!\n\n\n\n\n";
				}
				if (temp->kol == 0)
				{
					cout << "\n\t\t\t\t���� ����� ��� � �������!\n\n\n\n\n";
				}
			}
			else
			{
				
				cout << "\n\t\t\t\t� ���������� ����� � ����� ��� ���!\n\n\n\n\n" << endl;
			}
			system("pause");
		}
		if (vib == 2)
		{
			int c = 0;
			int udk;
			system("cls");
			cout << "\n\n\n\n\n\n\t\t\t\t������� ��� �����, ������� ������ �������: ";
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
					cout << "\n\t\t\t\t����� ����������!\n\n\n\n\n";
				
			}
			else
			{
				cout << "\n\t\t\t\t� ���������� ����� � ����� ��� �� ���������!\n\n\n\n\n" << endl;
			}
			system("pause");
		}
		if (vib == 3)
		{
			system("cls");
			cout << "\n\t\t\t\t\t������: " << endl;
			lst.Show();
			cout << "\n\n\n\n\n" << endl;
			system("pause");
		}
	}
	system("cls");
	cout << "\n\n\n\n\n\n\t\t\t\t�� ��������! =)\n\n\n\n"<< endl;
	system("pause");
	return 0;
}