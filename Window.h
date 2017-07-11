#pragma once

#include <Windows.h>

class Window {
public:
	Window(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow);
	void setPixel(int x, int y, COLORREF& color);
	void show(int iCmdShow);
	void update();

private:
	HWND hwnd;
};

inline LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	if (message == WM_CLOSE) { PostQuitMessage(0);  return 0; }
	return DefWindowProc(hwnd, message, wParam, lParam);
}
