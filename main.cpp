#include "Header.h"

void FixConsoleWindow() //cố định màn hình console (hàm thầy cho sẵn)
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void main()
{
	FixConsoleWindow();
	while (true)
	{
		int c = printMenu();
		option(c);
	}
}