#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char str[255];
	char string[255];
	int temp;
	cout << "Введите первоначальную строку" << endl;
	cin.getline(str, 255);
	_asm
	{
		mov ebx, 0;
		mov edx, 0;
	__next:
	cld
		xor ah, ah; 
		mov al, [str + ebx]
		lea edi, string
		mov ecx, 255
		_m1:
	repne scasb
		jne _m2
		inc ah
		jmp _m1
		_m2 :
	    cmp ah, 0;
		jne skip;
		
		mov [string + edx], al;
		inc edx;
		
		skip:
	inc ebx;
	cmp ebx, 255;
	jne __next;
}
	int size;
	size = strlen(string);
	int num[255]{ 0 };
		_asm {
			mov ebx, 0;
			_next:
			cld
			xor edx, edx; //здесь будет накапливаться	результат
			mov al, [string + ebx];
			lea edi, str
			mov ecx, 255
			m1:
			repne scasb
				jne m2
				inc edx
				jmp m1
				m2 :
			mov [num +  4*ebx], edx
				inc ebx;
			cmp ebx, 255;
				jne _next;
		}
		cout << "Ответ в формате символ - количество поторений" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << string[i] << " " << num[i] << endl;
	}
	system("pause");
	return 0;
}