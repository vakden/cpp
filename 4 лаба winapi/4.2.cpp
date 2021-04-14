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
//LPCSTR szClassName = "4.2";
//LPCSTR szTitle = "4.2";
//static int x =0,y=0,z=0,count=0;
//static bool pruf = false,rpruf= false,gpruf= false,ypruf=false;
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
//	SetTimer(hWnd, 1, 100, NULL);
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
//	HPEN rp, gp, yp,bp;
//	rp = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
//	gp = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
//	yp = CreatePen(PS_SOLID, 5, RGB(255, 255, 0));
//	bp = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
//	HBRUSH gf, rf, yf,bf,bbf;
//	rf = CreateSolidBrush(RGB(255, 0, 0));
//	gf = CreateSolidBrush(RGB(0, 255, 0));
//	yf = CreateSolidBrush(RGB(255, 255, 0));
//	bf= CreateSolidBrush(RGB(0, 0, 0));
//	bbf = CreateSolidBrush(RGB(0, 35, 55));
//	GetClientRect(hwnd, &rbl);
//	switch (message)
//	{
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
//		if (count == 26||count==56)
//		{
//			rpruf = false, gpruf = false, ypruf = true;
//			if (count == 56)
//				count = -5;
//		}
//		if (count == 0)
//		{
//			rpruf = false, gpruf = true, ypruf = false;
//		}
//		if (count == 30)
//		{
//			rpruf = true, gpruf = false, ypruf = false;
//		}
//		if (rpruf)
//		{
//			hDC = BeginPaint(hwnd, &ps);
//			SelectObject(hDC, bf);
//			Rectangle(hDC, rbl.right / 2 -50, rbl.bottom / 2 - 150, rbl.right / 2 + 50, rbl.bottom / 2 + 150);
//			SelectObject(hDC, rp);
//			SelectObject(hDC, rf);
//			Ellipse(hDC, rbl.right / 2 - 40, rbl.bottom / 2 - 140, rbl.right / 2 + 40, rbl.bottom / 2 - 60);
//			SelectObject(hDC, bp);
//			SelectObject(hDC, bbf);
//			Ellipse(hDC, rbl.right / 2 - 40, rbl.bottom / 2 - 50, rbl.right / 2 + 40, rbl.bottom / 2 + 30);
//			Ellipse(hDC, rbl.right / 2 - 40, rbl.bottom / 2 + 40, rbl.right / 2 + 40, rbl.bottom / 2 + 120);
//		}
//		if (ypruf)
//		{
//			hDC = BeginPaint(hwnd, &ps);
//			SelectObject(hDC, bf);
//			Rectangle(hDC, rbl.right / 2 - 50, rbl.bottom / 2 - 150, rbl.right / 2 + 50, rbl.bottom / 2 + 150);
//			SelectObject(hDC, bbf);
//			Ellipse(hDC, rbl.right / 2 - 40, rbl.bottom / 2 - 140, rbl.right / 2 + 40, rbl.bottom / 2 - 60);
//			SelectObject(hDC, yp);
//			SelectObject(hDC, yf);
//			Ellipse(hDC, rbl.right / 2 - 40, rbl.bottom / 2 - 50, rbl.right / 2 + 40, rbl.bottom / 2 + 30);
//			SelectObject(hDC, bp);
//			SelectObject(hDC, bbf);
//			Ellipse(hDC, rbl.right / 2 - 40, rbl.bottom / 2 + 40, rbl.right / 2 + 40, rbl.bottom / 2 + 120);
//			EndPaint(hwnd, &ps);
//		}
//		if (gpruf)
//		{
//			hDC = BeginPaint(hwnd, &ps);
//			SelectObject(hDC, bf);
//			Rectangle(hDC, rbl.right / 2 - 50, rbl.bottom / 2 - 150, rbl.right / 2 + 50, rbl.bottom / 2 + 150);
//			SelectObject(hDC, bbf);
//			Ellipse(hDC, rbl.right / 2 - 40, rbl.bottom / 2 - 140, rbl.right / 2 + 40, rbl.bottom / 2 - 60);
//			Ellipse(hDC, rbl.right / 2 - 40, rbl.bottom / 2 - 50, rbl.right / 2 + 40, rbl.bottom / 2 + 30);
//			SelectObject(hDC, gp);
//			SelectObject(hDC, gf);
//			Ellipse(hDC, rbl.right / 2 - 40, rbl.bottom / 2 + 40, rbl.right / 2 + 40, rbl.bottom / 2 + 120);
//			EndPaint(hwnd, &ps);
//		}
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hwnd, message, wParam, lParam);
//	}
//	return 0;
//}
//
