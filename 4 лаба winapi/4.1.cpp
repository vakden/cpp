#undef UNICODE 
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include<string>
#include <CommCtrl.h>
#include <WinUser.h>
#include <WinGDI.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI_4.1";
LPCSTR szTitle = "10_WinAPI_4_Ivanenko";
static int x = -160,count=1;
static bool pruf = false,tuda = true;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	if (!hPrevInstance)
	{
		if (!InitApplication(hInstance))
			return (FALSE);
	}
	if (!InitInstance(hInstance, nCmdShow))
		return (FALSE);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (msg.wParam);
}

BOOL InitApplication(HINSTANCE hInstance) {
	WNDCLASS  wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	wc.hCursor = LoadCursor(NULL, IDC_HAND);
	wc.hbrBackground = (HBRUSH)(COLOR_APPWORKSPACE - 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	// ������������ ����� ����   
	return RegisterClass(&wc);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow(
		szClassName,         // ��������� �� ������ ������������������� ����� ������     
		szTitle,             // ��������� �� ������ ��������� ����     
		WS_OVERLAPPEDWINDOW, // ����� ����     
		CW_USEDEFAULT,       //	�������������� ���������� ����     
		CW_USEDEFAULT,       // ������������ ���������� ����     
		CW_USEDEFAULT,       // ������ ����     
		CW_USEDEFAULT,       // ������ ����     
		NULL,                // ���������� ������������� ����     
		NULL,                // ���������� ���� ����     
		hInstance,           // ���������� ���������� ����������     
		NULL);               // ���������6 �� �������������� ������ ���� 

	if (!hWnd)
		return (FALSE);
	CreateWindow("BUTTON", "RUN", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 5, 5, 180, 30, hWnd, (HMENU)10000, hInstance, NULL);
	CreateWindow("BUTTON", "�������� � ����� ����", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 200, 5, 180, 30, hWnd, (HMENU)10001, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return (TRUE);
}



LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	RECT rbl;
	HDC hDC;
	PAINTSTRUCT ps;
	GetClientRect(hwnd, &rbl);
	switch (message)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case 10000:
		{
			SetTimer(hwnd, 1, 30, NULL);
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		case 10001:
		{
			count++;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		}
	}
	case WM_TIMER:
	{
		switch (wParam)
		{
		case 1:
		{
			x += 10;
			InvalidateRect(hwnd, NULL, TRUE);
			GetClientRect(hwnd, &rbl);
		}break;
		}
		break;
	}
	case WM_PAINT:
		if (count % 2 == 0)
			pruf = true;
		else
			pruf = false;
		if (rbl.right - x < rbl.left)
		{
			x = -160;
			if (pruf)
				tuda = false;
			else
				tuda = true;
		}
		if (tuda)
		{
			hDC = BeginPaint(hwnd, &ps);
			Ellipse(hDC, rbl.right - x, rbl.bottom, rbl.right - 60 - x, rbl.bottom - 60);
			Ellipse(hDC, rbl.right - 100 - x, rbl.bottom, rbl.right - 160 - x, rbl.bottom - 60);
			Rectangle(hDC, rbl.right - 30 - x, rbl.bottom - 30, rbl.right - 130 - x, rbl.bottom - 60);
			MoveToEx(hDC, rbl.right - 130 - x, rbl.bottom - 60, NULL);
			LineTo(hDC, rbl.right - 90 - x, rbl.bottom - 90);
			EndPaint(hwnd, &ps);
			break;
		}
		else
		{
			hDC = BeginPaint(hwnd, &ps);
			Ellipse(hDC, rbl.left + x, rbl.bottom, rbl.left + 60 + x, rbl.bottom - 60);
			Ellipse(hDC, rbl.left + 100 + x, rbl.bottom, rbl.left + 160 + x, rbl.bottom - 60);
			Rectangle(hDC, rbl.left + 30 + x, rbl.bottom - 30, rbl.left + 130 + x, rbl.bottom - 60);
			MoveToEx(hDC, rbl.left + 130 + x, rbl.bottom - 60, NULL);
			LineTo(hDC, rbl.left + 90 + x, rbl.bottom - 90);
			EndPaint(hwnd, &ps);
			break;
		}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}