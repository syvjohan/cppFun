#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>

struct Win
{
	HINSTANCE hInstance;
	HINSTANCE hPrevInstance;
	LPSTR lpCmdLine;
	int nCmdShow;
};

extern const char g_szClassName[];

class Window
{
public:
	Window();
	~Window();
	void CallingWINAPI();
	
private:
	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
protected:
};

#endif //!WINDOW_H