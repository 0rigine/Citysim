#include "stdafx.h"
#include "Display.h"
#include "City.h"
#include "Faction.h"

// FONCTIONS CONSOLE
void color(int t, int f) // Fonction de changement de couleur
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, f * 16 + t);
}

void adjustWindowSize() // Reajustement de la fenêtre
{
	struct SMALL_RECT test;

	HANDLE hStdout;
	COORD coord;
	BOOL ok;

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = 190;
	coord.Y = 48;
	ok = SetConsoleScreenBufferSize(hStdout, coord);

	test.Left = 0;
	test.Top = 0;
	test.Right = coord.X - 1;
	test.Bottom = coord.Y - 1;

	SetConsoleWindowInfo(hStdout, ok, &test);

}

void Locate(SHORT x, SHORT y) // placement du curseur
{
	HANDLE hmenu = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(hmenu, Pos);
}

// FONCTIONS UTILISATEUR
void Firstscreen() // accueil
{
	printf("\n");
	color(2, 0);
	Locate(70, 15);
	printf("====> Bienvenue dans Citysim <=====");
	color(15, 0);
}

void erase(int x, int y, int x_bis, int y_bis)
{
	Locate(x, y);
	for (int i = y; i < y_bis; i++)
	{
		for (int j = 0; j < x_bis; j++)
		{
			printf(" ");
		}
	}
}