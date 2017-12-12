#include "stdafx.h"

#include <windows.h>
#include <iostream>
#include <conio.h>

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
	_COORD coord;
	int Width(CONSOLE_Y), Height(CONSOLE_X);
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}

void locate(SHORT x, SHORT y) // placement du curseur
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
	locate(70, 15);
	printf("====> Bienvenue dans Citysim <=====");
	color(15, 0);
}

void erase(int x, int y, int x_bis, int y_bis)
{
	locate(x, y);
	for (int i = y; i < y_bis; i++)
	{
		for (int j = 0; j < x_bis; j++)
		{
			printf(" ");
		}
	}
}
int choix(const char* ch[], int taille, int x, int y) // Creation d'un menu
{
	int i, curseur = 0;
	locate(x, y);
	int y_bis = y;
	for (i = 0; i < taille; i++)
	{
		++y;
		printf("  %s\n", ch[i]);
		locate(x, y);
	}

	while (1) // gauche 0x4B   droite 0x77 haut 0x50  bas 0x48
	{
		int touche = _getch();
		locate(x, y_bis + curseur);
		printf(" ");
		if (touche == 0x50 && curseur < taille - 1)
			curseur++;
		if (touche == 0x48 && curseur > 0)
			curseur--;
		if (touche == 0x0D)
			return curseur + 1;
		locate(x, y_bis + curseur);
		printf(">");
		locate(189, 0);
	}
	return 0;
}

void our_faction(int x, int y)
{
	color(12, 0);
	locate(x, y); printf("_/-\\_");
	locate(x, y + 1); printf("| o |");
	locate(x, y + 2); printf("|_n_|");
	color(15, 0);
}