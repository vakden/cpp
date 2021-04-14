#undef UNICODE
#include <windows.h>
#include <winuser.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
LPCSTR szClassName = "WinAPI";
LPCSTR szTitle = "Создание окна Windows";
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int
	nCmdShow)
{

	MSG msg;
	/*хотя параметр hPrevInstance в Win32 всегда равно NULLпродолжаем проверять его
	значение */
	if (!hPrevInstance)
	{ /* инициализируем приложение - подготавливаем данные класса окна и
	  регистрируем его */
		if (!InitApplication(hInstance))
			return (FALSE);
	}
	/* завершаем создание копии приложения - создаем главное окно приложения */
	if (!InitInstance(hInstance, nCmdShow))
		return (FALSE);

	/* Цикл обработки сообщений */
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (msg.wParam);
}
BOOL InitApplication(HINSTANCE hInstance)
{
	WNDCLASS wc;
	// Заполняем структуру класса окна WNDCLASS
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
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
		szClassName, // указатель на строку зарегистрированного имени класса
		szTitle, // указатель на строку заголовка окна
		WS_OVERLAPPEDWINDOW, // стиль окна
		CW_USEDEFAULT, // горизонтальная координата окна
		CW_USEDEFAULT, // вертикальная координата окна
		CW_USEDEFAULT, // ширина окна
		CW_USEDEFAULT, // высота окна
		NULL, // дескриптор родительского окна
		NULL, // дескриптор меню окна
		hInstance, // дескриптор экземпляра приложения
		NULL); // указатель на дополнительные данные окна
	if (!hWnd) return (FALSE);
	ShowWindow(hWnd, SW_MINIMIZE);
	UpdateWindow(hWnd);
	return (TRUE);
}
LRESULT CALLBACK WndProc1(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	RECT rect;
	GetClientRect(hwnd, &rect);
	int x = 1300;
	HDC hDC;
	PAINTSTRUCT ps;
	HBRUSH brush;
	HPEN pen;
	switch (message)
	{
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
		pen = CreatePen( 1 , 2 , RGB(0, 0, 0));
		SelectObject(hDC, pen);
		brush = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hDC, brush);
		Rectangle(hDC, 0, 0, rect.right, rect.bottom);
		pen = CreatePen(1, 2, RGB(255, 215, 00));
		SelectObject(hDC, pen);
		brush = CreateSolidBrush(RGB(255, 215, 00));
		SelectObject(hDC, brush);
		Rectangle(hDC, 20, 20, x/2+20, x/2+20);
		pen = CreatePen(1, 2, RGB(100, 255, 100));
		SelectObject(hDC, pen);
		brush = CreateSolidBrush(RGB(100, 255, 100));
		SelectObject(hDC, brush);
		Rectangle(hDC, 50, 50, x / 2 - 10, x / 2 - 10);
		MoveToEx(hDC, x / 2 - 10 - 200, x / 2 - 10 - 160, NULL);
		pen = CreatePen(1, 2, RGB(0, 0, 0));
		SelectObject(hDC, pen);
		LineTo(hDC, x / 2 - 10 - 200, x / 2 - 10 - 100);
		LineTo(hDC, x / 2 - 10 - 140, x / 2 - 10 - 100);
		LineTo(hDC, x / 2 - 10 - 200, x / 2 - 10 - 160);
		brush = CreateSolidBrush(RGB(255, 0, 255));
		SelectObject(hDC, brush);
		FloodFill(hDC, x / 2 - 10 - 150, x / 2 - 10 - 105, RGB(0, 0, 0));

		LineTo(hDC, x / 2 - 10 - 360, x / 2 - 10 - 160);
		LineTo(hDC, x / 2 - 10 - 360, x / 2 - 10 - 100);
		LineTo(hDC, x / 2 - 10 - 300, x / 2 - 10 - 160);
		brush = CreateSolidBrush(RGB(255, 0, 0));
		SelectObject(hDC, brush);
		FloodFill(hDC, x / 2 - 10 - 350, x / 2 - 10 - 150, RGB(0, 0, 0));
		
		LineTo(hDC, x / 2 - 10 - 320, x / 2 - 10 - 160);
		LineTo(hDC, x / 2 - 10 - 260, x / 2 - 10 - 220);
		LineTo(hDC, x / 2 - 10 - 180, x / 2 - 10 - 140);
		brush = CreateSolidBrush(RGB(255, 200, 200));
		SelectObject(hDC, brush);
		FloodFill(hDC, x / 2 - 10 - 260, x / 2 - 10 - 200, RGB(0, 0, 0));

		LineTo(hDC, x / 2 - 10 - 180, x / 2 - 10 - 300);
		LineTo(hDC, x / 2 - 10 - 260, x / 2 - 10 - 220);
		brush = CreateSolidBrush(RGB(0, 0, 255));
		SelectObject(hDC, brush);
		FloodFill(hDC, x / 2 - 10 - 240,x / 2 - 10 - 220, RGB(0, 0, 0));

		LineTo(hDC, x / 2 - 10 - 260, x / 2 - 10 - 300);
		LineTo(hDC, x / 2 - 10 - 220, x / 2 - 10 - 340);
		LineTo(hDC, x / 2 - 10 - 220, x / 2 - 10 - 260);
		brush = CreateSolidBrush(RGB(255, 200, 0));
		SelectObject(hDC, brush);
		FloodFill(hDC, x / 2 - 10 - 240, x / 2 - 10 - 260, RGB(0, 0, 0));

		LineTo(hDC, x / 2 - 10 - 140, x / 2 - 10 - 340);
		LineTo(hDC, x / 2 - 10 - 240, x / 2 - 10 - 440);

		LineTo(hDC, x / 2 - 10 - 200, x / 2 - 10 - 480);
		LineTo(hDC, x / 2 - 10 - 160, x / 2 - 10 - 440);
		LineTo(hDC, x / 2 - 10 - 200, x / 2 - 10 - 400);
		brush = CreateSolidBrush(RGB(0, 255, 0));
		SelectObject(hDC, brush);
		FloodFill(hDC, x / 2 - 10 - 200, x / 2 - 10 - 460, RGB(0, 0, 0));

		LineTo(hDC, x / 2 - 10 - 220, x / 2 - 10 - 420);
		LineTo(hDC, x / 2 - 10 - 220, x / 2 - 10 - 260);
		brush = CreateSolidBrush(RGB(255, 100, 0));
		SelectObject(hDC, brush);
		FloodFill(hDC, x / 2 - 10 - 150, x / 2 - 10 - 340, RGB(0, 0, 0));
		
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
