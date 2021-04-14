//#undef UNICODE 
//#define _CRT_SECURE_NO_WARNINGS
//#include <windows.h>
//#include<string>
//#include <CommCtrl.h>
//#include <WinUser.h>
//#include <WinGDI.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
//BOOL InitApplication(HINSTANCE hInstance);
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
//
//LPCSTR szClassName = "4.3";
//LPCSTR szTitle = "4.3";
//static int x = 0, y = 0, z = 0, count = 0;
//static bool pruf = false, onepruf = false, twopruf = false, threepruf = false;
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
//	SetTimer(hWnd, 1, 500, NULL);
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);
//	return (TRUE);
//}
//
//
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
//	RECT rbl;
//	HDC hDC;
//	PAINTSTRUCT ps;
//	HPEN rp, gp, yp, bp;
//	rp = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
//	gp = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
//	yp = CreatePen(PS_SOLID, 5, RGB(255, 255, 0));
//	bp = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
//	HBRUSH brush;
//	GetClientRect(hwnd, &rbl);
//	switch (message)
//	{
//	case WM_LBUTTONDOWN:
//		if (LOWORD(lParam) >= rbl.left + 10 && LOWORD(lParam) <= rbl.left + 310 && HIWORD(lParam) >= rbl.top + 10 && HIWORD(lParam) <= rbl.top + 310)
//		{
//			onepruf = true;
//		}
//		if (LOWORD(lParam) >= rbl.left + 10 && LOWORD(lParam) <= rbl.left + 800 && HIWORD(lParam) >= rbl.top + 400 && HIWORD(lParam) <= rbl.top + 600)
//		{
//			twopruf = true;
//		}
//		if (LOWORD(lParam) >= rbl.left + 330 && LOWORD(lParam) <= rbl.left + 800 && HIWORD(lParam) >= rbl.top + 10 && HIWORD(lParam) <= rbl.top + 310)
//		{
//			threepruf = true;
//		}
//		break;
//	case WM_RBUTTONDOWN:
//		if (LOWORD(lParam) >= rbl.left + 10 && LOWORD(lParam) <= rbl.left + 800 && HIWORD(lParam) >= rbl.top + 10 && HIWORD(lParam) <= rbl.top + 310)
//		{
//			onepruf = false;
//		}
//		if (LOWORD(lParam) >= rbl.left + 10 && LOWORD(lParam) <= rbl.left + 800 && HIWORD(lParam) >= rbl.top + 400 && HIWORD(lParam) <= rbl.top + 600)
//		{
//			twopruf = false;
//		}
//		if (LOWORD(lParam) >= rbl.left + 330 && LOWORD(lParam) <= rbl.left + 240 && HIWORD(lParam) >= rbl.top + 10 && HIWORD(lParam) <= rbl.top + 310)
//		{
//			threepruf =false;
//		}
//		break;
//	case WM_TIMER:
//	{
//		switch (wParam)
//		{
//		case 1:
//		{
//			count++;
//			InvalidateRect(hwnd, NULL, TRUE);
//			GetClientRect(hwnd, &rbl);
//		}break;
//		}
//		break;
//	}
//	case WM_PAINT:
//		if (onepruf)
//		{
//			if (count % 2 == 0)
//				x = 10;
//			else
//				x = -10;
//		}
//		else
//			x = 0;
//		if (twopruf)
//		{
//			if (count % 2 == 0)
//				y = 10;
//			else
//				y = -10;
//		}
//		else
//			y = 0;
//		if (threepruf)
//		{
//			if (count % 2 == 0)
//				z = 10;
//			else
//				z = -10;
//		}
//		else
//			z = 0;
//		hDC = BeginPaint(hwnd, &ps);
//		brush = CreateSolidBrush(RGB(255, 0, 0));
//		SelectObject(hDC, brush);
//		Ellipse(hDC, rbl.left+10-x, rbl.top+ 10-x, rbl.left + 310+x, rbl.top + 310+x);
//		brush = CreateSolidBrush(RGB(0, 255, 0));
//		SelectObject(hDC, brush);
//		Ellipse(hDC, rbl.left + 10-y, rbl.top + 400-y, rbl.left + 800+y, rbl.top + 600+y);
//		brush = CreateSolidBrush(RGB(0, 0, 255));
//		SelectObject(hDC, brush);
//		Rectangle(hDC, rbl.left + 330-z, rbl.top + 10-z, rbl.left + 800+z, rbl.top + 310+z);
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
