#include <iostream>

using namespace std;

void main()
{
	const int max = 32;
	int arr[max];
	int chislo, c = 0, sum, N, num, q = 10;
	cout << "Enter N" << endl;
	cin >> N;
	__asm
	{
		
		L:   
		    mov sum, 0
		    dec N
			mov ecx, N
			mov chislo, ecx
		    mov eax, chislo
			mov ebx, 0
			K :
			cdq
	 		div q
			inc ebx
			cmp   eax, 0
			jne   K
			mov num, ebx
			mov eax, chislo
			L1 :
		
			cmp eax, 0
			je L2
			mov ecx, num
			cdq
			div q
			mov ebx, eax
			mov eax, 1
			W1:
		    cmp ecx, 0
		    je W2
		    dec ecx
			imul eax, edx;
		    jmp W1
			W2:
		    add sum, eax
		    mov eax, ebx
		    jmp L1
		    L2 :
		    mov eax, chislo 
		    cmp eax, sum
		    jne G
			mov eax, sum;
			mov ebx, c
			mov [arr + ebx * 4], eax;
			inc ebx;
			mov c, ebx
			G:
		    mov ecx, N
			cmp N, 0
		    jne L
	}
	cout << "Array" << endl;
	for (int i = 0; i < c; i++)
	{
		cout << arr[i] << endl;
	}
	system("pause");
}
