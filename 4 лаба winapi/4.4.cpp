//#define _CRT_SECURE_NO_WARNINGS
//#undef UNICODE 
//#include <windows.h>
//#include <windows.h>
//#include<string>
//#include <CommCtrl.h>
//#include <WinUser.h>
//#include <WinGDI.h>
////a=0 b=300
//LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
//BOOL InitApplication(HINSTANCE hInstance);
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
//
//LPCSTR szClassName = "4.4";
//LPCSTR szTitle = "4.4";
//static int func=1;
//double  x = 0, y = 0, X = 0, Y = 0;
//HMENU hMenu;
//HWND hDiag1;
//double function(double x, double f)
//{
//	if (f == 1)
//		return 100*sin(x/100);
//	if (f == 2)
//		return x*x/30;
//	if (f == 3)
//		return x / 2;
//	if (f == 4)
//		return -sqrt(x)*10;
//}
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	MSG msg;
//	if (!hPrevInstance)
//	{
//		if (!InitApplication(hInstance))
//			return (FALSE);
//	}
//	if (!InitInstance(hInstance, nCmdShow))
//		return (FALSE);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//	return (msg.wParam);
//}
//
//
//
//BOOL InitApplication(HINSTANCE hInstance) {
//	WNDCLASS  wc;
//	wc.style = CS_HREDRAW | CS_VREDRAW;
//	wc.lpfnWndProc = (WNDPROC)WndProc;
//	wc.cbClsExtra = 0;
//	wc.cbWndExtra = 0;
//	wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_ASTERISK);
//	wc.hCursor = LoadCursor(NULL, IDC_HAND);
//	wc.hbrBackground = (HBRUSH)(COLOR_APPWORKSPACE - 1);
//	wc.lpszMenuName = NULL;
//	wc.lpszClassName = szClassName;
//	// Регистрируем класс окна   
//	return RegisterClass(&wc);
//}
//
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
//{
//	HWND hWnd;
//	hWnd = CreateWindow(
//		szClassName,         // указатель на строку зарегистрированного имени класса     
//		szTitle,             // указатель на строку заголовка окна     
//		WS_OVERLAPPEDWINDOW, // стиль окна     
//		CW_USEDEFAULT,       //	горизонтальная координата окна     
//		CW_USEDEFAULT,       // вертикальная координата окна     
//		CW_USEDEFAULT,       // ширина окна     
//		CW_USEDEFAULT,       // высота окна     
//		NULL,                // дескриптор родительского окна     
//		NULL,                // дескриптор меню окна     
//		hInstance,           // дескриптор экземпляра приложения     
//		NULL);               // указатель6 на дополнительные данные окна 
//
//	if (!hWnd)
//		return (FALSE);
//	CreateWindow("BUTTON", "y = 100*sin(x/100)", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 5, 0 , 155, 30, hWnd, (HMENU)10000, hInstance, NULL);
//	CreateWindow("BUTTON", "y = x*x/30", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 160, 0, 155, 30, hWnd, (HMENU)10001, hInstance, NULL);
//	CreateWindow("BUTTON", "y = x/2", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 315, 0, 155, 30, hWnd, (HMENU)10002, hInstance, NULL);
//	CreateWindow("BUTTON", "y = -x^(1/2)*10", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 470, 0, 155 , 30, hWnd, (HMENU)10003, hInstance, NULL);
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);
//	return (TRUE);
//}
//
//
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
//	RECT rbl;
//	HPEN Pen;
//	Pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
//	GetClientRect(hwnd, &rbl);
//	HDC hDC;
//	PAINTSTRUCT ps;
//	switch (message)
//	{
//	case WM_COMMAND:
//	{
//		switch (wParam)
//		{
//		case 10000:
//			func = 1;
//			X = rbl.left + 15;
//			Y = rbl.bottom - 15;
//			x = 0;
//			InvalidateRect(hwnd, NULL, TRUE);
//			break;
//		case 10001:
//			func = 2;
//			X = rbl.left + 15;
//			Y = rbl.bottom - 15;
//			x = 0;
//			InvalidateRect(hwnd, NULL, TRUE);
//			break;
//		case 10002:
//			func = 3;
//			X = rbl.left + 15;
//			Y = rbl.bottom - 15;
//			x = 0;
//			InvalidateRect(hwnd, NULL, TRUE);
//			break;
//		case 10003:
//			func = 4;
//			X = rbl.left + 15;
//			Y = rbl.bottom - 15;
//			x = 0;
//			InvalidateRect(hwnd, NULL, TRUE);
//			break;
//		}
//	}
//	case WM_PAINT:
//		hDC = BeginPaint(hwnd, &ps);
//		SelectObject(hDC, Pen);
//		Rectangle(hDC, rbl.left + 10, rbl.top + 10, rbl.right - 10, rbl.bottom - 10);
//		MoveToEx(hDC, rbl.left + 15, rbl.bottom / 2, NULL);
//		LineTo(hDC, rbl.right -15, rbl.bottom/2);
//		MoveToEx(hDC, rbl.left+15, rbl.bottom/2, NULL);
//		TextOut(hDC, rbl.right - 30, rbl.bottom / 2 - 20, "X", 1);
//		TextOut(hDC, 20, 40, "Y", 1);
//		X = rbl.left + 15;
//		Y = rbl.bottom/2;
//		Pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
//		SelectObject(hDC, Pen);
//		do
//		{
//			x+= 0.01;
//			y = function(x,func);
//			SetPixel(hDC, X, Y, RGB(255, 0, 0));
//			X = rbl.left + 15 + x;
//			Y = rbl.bottom/2 - y;
//		} while (X <= rbl.right - 15 && Y >= 15 && Y<rbl.bottom -15);
//		EndPaint(hwnd, &ps);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hwnd, message, wParam, lParam);
//	}
//	return 0;
//}