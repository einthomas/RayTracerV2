#include <iostream>

#include "Window.h"
#include "World.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow) {
	AllocConsole();
	FILE* pCout;
	freopen_s(&pCout, "CONOUT$", "w", stdout);

	Window window(hInstance, hPrevInstance, lpCmdLine, iCmdShow);
	window.show(iCmdShow);
	window.update();

	World world(&window);
	world.build();
	world.renderScene();

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
