#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE
#include <windows.h>
#include<string>
#include <CommCtrl.h>
#include <WinUser.h>
#include <WinGDI.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char szClassName[] = "ClassName";
HMENU hMenu;
HWND hDiag1;
static bool f = false, r = true;
double X, Y, x, y;
int t = 0; double six = 0;
bool flag = false;
bool mouse = false;
void displayDialog1(HWND hWnd)
{
	hDiag1 = CreateWindow("MyDialogClass", "Новый рисунок", WS_VISIBLE | WS_OVERLAPPED | WS_POPUP | WS_CAPTION | WS_BORDER | WS_SYSMENU,
		300, 200, 500, 300,
		hWnd, NULL, NULL, NULL);
}

LRESULT CALLBACK DialogProcedure1(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	SIZE s;
	PAINTSTRUCT pS;
	RECT rect1;
	GetClientRect(hWnd, &rect1);
	HDC hDc;
	switch (msg)
	{
	case WM_CLOSE:
	{
		DestroyWindow(hWnd);
		break;
	}
	case WM_PAINT:
	{
		hDc = BeginPaint(hWnd, &pS);
		TextOut(hDc, 0, 0, "Контрольная работа WinAPI", 25);
		GetTextExtentPoint32(hDc, "Вакулича Дениса Викторовича", 28, &s);
		TextOut(hDc, rect1.right / 2 - s.cx / 2, rect1.bottom / 2, "Вакулича Дениса Викторовича", 28);
		EndPaint(hWnd, &pS);
		break;
	}
	default:
	{
		return DefWindowProc(hWnd, msg, wp, lp);
	}
	}
}

void RegisterDialog(HINSTANCE hInst)
{

	WNDCLASS dialog = { 0 };
	dialog.lpszClassName = "MyDialogClass";
	dialog.hInstance = hInst;
	dialog.lpfnWndProc = DialogProcedure1;
	dialog.hCursor = LoadCursor(NULL, IDC_ARROW);
	dialog.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	dialog.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	dialog.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	RegisterClass(&dialog);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE HPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG msg;
	WNDCLASS wcApp;
	wcApp.lpszClassName = szClassName;
	wcApp.hInstance = hInstance;
	wcApp.lpfnWndProc = WndProc;
	wcApp.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcApp.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcApp.lpszMenuName = 0;
	wcApp.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcApp.style = 0;
	wcApp.cbClsExtra = 0;
	wcApp.cbWndExtra = 0;
	if (!RegisterClass(&wcApp))
	{
		MessageBox(NULL, "Class hasn't been registered", "RegisterClass", MB_OK);
		return 0;
	}
	RegisterDialog(hInstance);
	hWnd = CreateWindow(szClassName, "Snegovik", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, 0, hInstance, 0);
	CreateWindow("BUTTON", "RUN", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 5, 5, 180, 30, hWnd, (HMENU)10000, hInstance, NULL);
	CreateWindow("BUTTON", "STOP", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 300, 5, 180, 30, hWnd, (HMENU)10001, hInstance, NULL);
	ShowWindow(hWnd, SW_MAXIMIZE);
	UpdateWindow(hWnd);
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (msg.wParam);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;
	HPEN pen;
	GetClientRect(hWnd, &rect);
	X = rect.left;
	Y = rect.bottom / 2;
	switch (message)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case 10000:
		{
			SetTimer(hWnd, 1, 30, NULL);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
		case 10001:
		{
			KillTimer(hWnd, 1);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
		}
		break;
	}
	case WM_TIMER:
	{
		switch (wParam)
		{
		case 1:
		{
			six = (double)t/10;
			x = t*5;
			y = 100 * sin(x / 100);
			InvalidateRect(hWnd, NULL, TRUE);
		}break;
		}
		break;
	}
	case WM_PAINT:
	{

				hDC = BeginPaint(hWnd, &ps);
				pen = CreatePen(1, 2, RGB(0, 0, 0));
				SelectObject(hDC, pen);
				X = (double)rect.left + x;
				Y = (double)rect.bottom / 2 - y;
				Ellipse(hDC, (int)X, (int)Y - 40, (int)X + 80, (int)Y + 40);
			if(mouse == true)
				{
					MoveToEx(hDC, (int)X + 40, (int)Y, NULL);
					LineTo(hDC, (int)(X + 40 + 40 * cos(six)), (int)(Y + 40 * sin(six)));
				}
				if (X > rect.right - 80)
				{
					flag = true;
				}
				if (X < 0)
				{
					flag = false;
				}
			    if(flag == true)
			    {
					t--;
			    }
			    if (flag != true)
			    {
					t++;
			    }
				EndPaint(hWnd, &ps);
	}break;
	case WM_LBUTTONDOWN:
	{
		if (LOWORD(lParam) >= 0 && LOWORD(lParam) <= rect.right && HIWORD(lParam) >= 0 && HIWORD(lParam) <= rect.bottom)
		{
			mouse = !mouse;
		}
	}
	case WM_SIZE:
	{
		InvalidateRect(hWnd, NULL, true);
	}break;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

