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
		font.lfHeight = 32+2*mas;// Устанавливает высоту шрифта или символа
		font.lfWidth = 16+1*mas;// Устанавливает среднюю ширину символов в шрифте
		font.lfEscapement = 0;// Устанавливает угол, между вектором наклона и осью X устройства
		font.lfOrientation = 0;// Устанавливает угол, между основной линией каждого символа и осью X устройства
		font.lfWeight = 1000;// Устанавливает толщину шрифта в диапазоне от 0 до 1000
		font.lfItalic = 0;// Устанавливает курсивный шрифт
		font.lfUnderline = 0;// Устанавливает подчеркнутый шрифт
		font.lfStrikeOut = 0;// Устанавливает зачеркнутый шрифт
		font.lfCharSet = RUSSIAN_CHARSET;// Устанавливает набор символов
		font.lfOutPrecision = 0;// Устанавливает точность вывода
		font.lfClipPrecision = 0;// Устанавливает точность отсечения
		font.lfQuality = 0;// Устанавливает качество вывода
		font.lfPitchAndFamily = 0;// Устанавливает ширину символов и семейство шрифта
		strcpy(font.lfFaceName, "TimesNewRoman");//  устанавливает название шрифта
		hfont = ::CreateFontIndirect(&font);
		SelectObject(hDC, hfont);
		if (mas >= -4)
		{
			TextOut(hDC, x * 3 / 4 + 10 * mas - 7 * font.lfWidth - 6 * (mas + 4) - 2 - 40, y * 3 / 4 + 10 * mas - font.lfHeight - 2 - 20, "Вакулич", 7);
		}
		if (mas < -4)
		{
			TextOut(hDC, x * 3 / 4 + 10 * mas - 7 * font.lfWidth + 6 * (mas + 4) - 2 - 40, y * 3 / 4 + 10 * mas - font.lfHeight - 2 - 20, "Вакулич", 7);
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
