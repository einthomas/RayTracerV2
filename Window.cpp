#include "Window.h"

Window::Window(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow) {
	static TCHAR szAppName[] = TEXT("Test");
	WNDCLASS wndclass;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	if (!RegisterClass(&wndclass)) {
		MessageBox(NULL, "Registering the class failed", "Error", MB_OK | MB_ICONERROR);
		exit(0);
	}

	hwnd = CreateWindow(szAppName, "Raytracer",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	if (!hwnd) {
		MessageBox(NULL, "Window Creation Failed!", "Error", MB_OK);
		exit(0);
	}

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
}

void Window::setPixel(int x, int y, COLORREF& color) {
	if (hwnd == NULL) {
		MessageBox(NULL, "sHwnd was not initialized !", "Error", MB_OK | MB_ICONERROR);
		exit(0);
	}
	HDC hdc = GetDC(hwnd);
	SetPixel(hdc, x, y, color);
	ReleaseDC(hwnd, hdc);
}

void Window::show(int iCmdShow) {
	ShowWindow(hwnd, iCmdShow);
}

void Window::update() {
	UpdateWindow(hwnd);
}
