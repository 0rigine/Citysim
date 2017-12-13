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
	dim.Y /= 10000;
}

void Console::showConsoleCursor(bool showBool)
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(console, &cursorInfo);
	cursorInfo.bVisible = showBool;
	SetConsoleCursorInfo(console, &cursorInfo);
}

void Console::erase(int x, int y, int x_bis, int y_bis)
{
	for (int i = y; i <= y_bis; i++)
	{
		locate(x, i);
		for (int j = x; j <= x_bis; j++)
		{
			cout << " ";
		}
	}
}

void Console::firstscreen()
{
	string text("=====> Bienvenue dans Citysim <=====");
	int sizeText = text.size();
	color(2, 0);
	locate(dim.X/2, 15);
	cout << text << endl;
	color(DEFAULT_COLOR, 0);
	locate(dim.X / 2, 20);
}

int Console::choix(vector<string> ch, int x, int y)
{
	int curseur(0),
		y_bis(y),
		taille(ch.size());
	showConsoleCursor();
	locate(x+2, y);
	for (int i = 0; i < taille; i++)
	{
		++y;
		cout << ch[i] << endl;
		locate(x+2, y);
	}
	while (true)
	{
		int touche = _getch();
		locate(x, y_bis + curseur);
		cout << " ";
		if (touche == 0x50 && curseur < taille - 1)
		{
			curseur++;
		}
		else if (touche == 0x48 && curseur > 0)
		{
			curseur--;
		}
		else if (touche == 0x0D)
		{
			return curseur;
		}
		locate(x, y_bis + curseur);
		cout << ">";
	}
}
