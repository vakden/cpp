#undef UNICODE 
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include<string>
#include <CommCtrl.h>
#include <WinUser.h>
#include <WinGDI.h>
#include <math.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "3.2";
LPCSTR szTitle = "3.2";
static int x = 0, y = 0, z = 0, count = -1;
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
	// Регистрируем класс окна   
	return RegisterClass(&wc);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow(
		szClassName,         // указатель на строку зарегистрированного имени класса     
		szTitle,             // указатель на строку заголовка окна     
		WS_OVERLAPPEDWINDOW, // стиль окна     
		CW_USEDEFAULT,       //	горизонтальная координата окна     
		CW_USEDEFAULT,       // вертикальная координата окна     
		CW_USEDEFAULT,       // ширина окна     
		CW_USEDEFAULT,       // высота окна     
		NULL,                // дескриптор родительского окна     
		NULL,                // дескриптор меню окна     
		hInstance,           // дескриптор экземпляра приложения     
		NULL);               // указатель6 на дополнительные данные окна 

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
	bool flag = 1;
	double sin = y/2;
	double cos = sqrt(y*y/4 - sin*sin);
	switch (message)
	{
	case WM_LBUTTONDOWN:
		if (LOWORD(lParam) >= 0 && LOWORD(lParam) <= x && HIWORD(lParam) >= 0 && HIWORD(lParam) <= y)
		{
			SetTimer(hwnd, 1, 30, NULL);
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		break;
	case WM_RBUTTONDOWN:
		if (LOWORD(lParam) >= 0 && LOWORD(lParam) <= x && HIWORD(lParam) >= 0 && HIWORD(lParam) <= y)
		{
			KillTimer(hwnd, 1);
			count = -1;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		break;
	case WM_TIMER:
	{
		switch (wParam)
		{
		case 1:
		{
			InvalidateRect(hwnd, NULL, TRUE);
			GetClientRect(hwnd, &rect);
		}break;
		}
		break;
	}
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
			count++;
		Ellipse(hDC, 0, 0, y, y);
		MoveToEx(hDC, y / 2, 0, NULL);
		LineTo(hDC, y / 2, 25);
		MoveToEx(hDC, 0, y/2, NULL);
		LineTo(hDC, 25 , y / 2);
		MoveToEx(hDC, y, y / 2, NULL);
		LineTo(hDC, y - 25, y / 2);
		MoveToEx(hDC, y/2, y, NULL);
		LineTo(hDC, y/2 , y-25);
		if (count == 2*y)
		{
			count = 0;
		}
			sin = count;
			cos = sqrt((double)y*y / 4 - ((double)y/2 - sin)*((double)y/2 - sin));
			MoveToEx(hDC, y / 2, y / 2, NULL);
			LineTo(hDC, y / 2 + (int)cos, (int)sin);
			sin = 2 * y - count;
			cos = sqrt((double)y*y / 4 - ((double)y / 2 - y + sin)*((double)y / 2 -y + sin));
			MoveToEx(hDC, y / 2, y / 2, NULL);
			LineTo(hDC, y / 2 - (int)cos, (int)sin);
			EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_ACTIVATE:
		{
		KillTimer(hwnd, 1);
		}
	case WM_CHAR:
	{
		KillTimer(hwnd, 1);
	}
	default:
	{
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	}
	return 0;
}
