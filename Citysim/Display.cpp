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

int Console::choix(vector<string> ch, int x, int y, vector<int> values)
{
	int curseur(0),
		y_bis(y),
		taille(ch.size()),
		sizeValue(values.size());
	showConsoleCursor();
	locate(x+2, y);
	for (int i = 0; i < taille; i++)
	{
		++y;
		cout << ch[i];
		if (sizeValue == taille) cout << " " << values[i];
		cout << endl;
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

void Console::choiceTown(int * choice_x, int * choice_y, int taille_x, int taille_y)
{
	int curseur_x(0),
		curseur_y(0),
		touche(0);
	while (true)
	{
		touche = _getch();
		Console::locate(0 + curseur_x * 8, 2 + curseur_y * 4);
		cout << " ";
		if (touche == 0x50 && curseur_y < taille_y - 1) // haut
		{
			curseur_y++;
		}
		if (touche == 0x48 && curseur_y > 0) // bas
			curseur_y--;

		if (touche == 0x4D && curseur_x < taille_x - 1) // droite
		{
			curseur_x++;
		}
		if (touche == 0x4B && curseur_x > 0) // gauche
			curseur_x--;

		if (touche == 0x0D)
		{
			(*choice_x) = 2 + curseur_x * 8;
			(*choice_y) = 1 + curseur_y * 4;
			return;
		}
		Console::locate(0 + curseur_x * 8, 2 + curseur_y * 4);
		cout << ">";
	}
}
