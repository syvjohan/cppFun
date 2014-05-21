#include "window.h"

Window::Window()
{

}

Window::~Window()
{

}

int WINAPI Window::WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	char g_szClassName[] = "My window";

	MessageBox(NULL, "Goodbye, cruel world!", "Note", MB_OK);

	return 0;
}

void Window::CallingWINAPI() {

	struct Win win;

	win.hInstance = NULL;
	win.hPrevInstance = NULL;
	win.lpCmdLine = NULL;
	win.nCmdShow = 0;

	WinMain(win.hInstance, win.hPrevInstance, win.lpCmdLine, win.nCmdShow);
}


