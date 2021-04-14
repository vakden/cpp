.386
public Function
.model flat
.stack
.data
.code
org 100h
Extrn C min: BYTE
Function PROC C arr1: dword, count: dword, N: dword;

mov esi, arr1;
mov edx, count;
mov ebx, 0;
 mov ecx, 0;
_next:
   mov eax, [esi + 4*ecx];
    cmp eax, (-2)
   jl _skip;
   cmp eax, 7
   jg _skip;
   inc ebx;
   _skip:
inc ecx;
dec edx;
cmp edx, 0
ja _next
cmp ebx, 0
je exit;

  mov edx, ebx;
    mov ecx, 0;
next:
   mov eax, [esi + 4*ecx];
    mov ebx, ecx;
     cmp eax, (-2)
   jl skip;
   cmp eax, 7
   jg skip;
   dec edx;
	   				
					     sdvig:
					   inc ecx;
					   mov eax, [esi + 4*ecx];
					   dec ecx;
					   mov [esi + 4*ecx], eax;
					   inc ecx;
					     cmp ecx, count
					     jb sdvig;
						mov ecx, count;
						dec ecx;
						mov eax, 0;
						mov [esi + 4*ecx], eax;
						dec count;
skip:
mov ecx, ebx;
inc ecx;
cmp edx, 0
jne next
exit:
	ret 4
Function endp

end;
