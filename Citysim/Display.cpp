#include "stdafx.h"

#include <windows.h>
#include <iostream>
#include <conio.h>

#include <string>

#include "Display.h"
#include "City.h"
#include "Faction.h"

HANDLE Console::console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Console::dim = GetLargestConsoleWindowSize(Console::console);

void Console::color(int t, int f)
{
	SetConsoleTextAttribute(console, f * 16 + t);
}

void Console::locate(SHORT x, SHORT y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(console, Pos);
}

void Console::adjustWindowSize()
{
	SetConsoleDisplayMode(console, CONSOLE_FULLSCREEN_MODE, &dim);
}

void Console::showConsoleCursor(bool showBool)
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(console, &cursorInfo);
	cursorInfo.bVisible = showBool;
	SetConsoleCursorInfo(console, &cursorInfo);
}
