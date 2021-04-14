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

LPCSTR szClassName = "3.1";
LPCSTR szTitle = "3.1";
static int x = 0, y = 0, z = 0, count = 0;
int mas = 0;
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
	SetTimer(hWnd, 1, 500, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return (TRUE);
}



LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;
	LOGFONT font;
	HFONT hfont;
	GetClientRect(hwnd, &rect);
	x = rect.right;
	y = rect.bottom;
	int a = 0;
	switch (message)
	{
	case WM_LBUTTONDOWN:
		if (LOWORD(lParam) >= x / 4 && LOWORD(lParam) <= x * 3 / 4 && HIWORD(lParam) >= y / 4 && HIWORD(lParam) <= y * 3 / 4)
		{
			if (mas < 10)
			mas++;
		}
		break;
	case WM_RBUTTONDOWN:
		if (LOWORD(lParam) >= x / 4 && LOWORD(lParam) <= x * 3 / 4 && HIWORD(lParam) >= y / 4 && HIWORD(lParam) <= y * 3 / 4)
		{
			if (mas > -10)
			mas--;
		}
		break;
	case WM_TIMER:
	{
		switch (wParam)
		{
		case 1:
		{
			count++;
			InvalidateRect(hwnd, NULL, TRUE);
			GetClientRect(hwnd, &rect);
		}break;
		}
		break;
	}
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
		Rectangle(hDC, x/4-10*mas, y/4-10*mas, x*3/4+10*mas, y*3/4+10*mas);
		font.lfHeight = 32+2*mas;// ������������� ������ ������ ��� �������
		font.lfWidth = 16+1*mas;// ������������� ������� ������ �������� � ������
		font.lfEscapement = 0;// ������������� ����, ����� �������� ������� � ���� X ����������
		font.lfOrientation = 0;// ������������� ����, ����� �������� ������ ������� ������� � ���� X ����������
		font.lfWeight = 1000;// ������������� ������� ������ � ��������� �� 0 �� 1000
		font.lfItalic = 0;// ������������� ��������� �����
		font.lfUnderline = 0;// ������������� ������������ �����
		font.lfStrikeOut = 0;// ������������� ����������� �����
		font.lfCharSet = RUSSIAN_CHARSET;// ������������� ����� ��������
		font.lfOutPrecision = 0;// ������������� �������� ������
		font.lfClipPrecision = 0;// ������������� �������� ���������
		font.lfQuality = 0;// ������������� �������� ������
		font.lfPitchAndFamily = 0;// ������������� ������ �������� � ��������� ������
		strcpy(font.lfFaceName, "TimesNewRoman");//  ������������� �������� ������
		hfont = ::CreateFontIndirect(&font);
		SelectObject(hDC, hfont);
		if (mas >= -4)
		{
			TextOut(hDC, x * 3 / 4 + 10 * mas - 7 * font.lfWidth - 6 * (mas + 4) - 2 - 40, y * 3 / 4 + 10 * mas - font.lfHeight - 2 - 20, "�������", 7);
		}
		if (mas < -4)
		{
			TextOut(hDC, x * 3 / 4 + 10 * mas - 7 * font.lfWidth + 6 * (mas + 4) - 2 - 40, y * 3 / 4 + 10 * mas - font.lfHeight - 2 - 20, "�������", 7);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
