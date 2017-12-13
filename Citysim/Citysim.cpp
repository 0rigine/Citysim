#include "stdafx.h"
#include <random>
#include <time.h>
#include <iostream>
#include <Windows.h>
using namespace std;
#include "Grille.h"
#include "Display.h"

// PROTOTYPES
void lancerPartie(int sizex = 2, int sizey = 2); // lancement d'une partie
void menu(); // menu de jeu


// PROGRAMME PRINCIPAL
int main()
{
	srand(time(NULL));

	Console::adjustWindowSize();
	Console::showConsoleCursor();
	menu();
    return 0;
}

// DEFINITIONS
void lancerPartie(int sizex, int sizey)
{
	system("cls");
	Grille game = Grille(sizex, sizey);
	game.playAGame();
}

void menu()
{
	vector<string> tab_menu_principal(
	{
		"Jouer",
		"Credit",
		"Quitter"
	});
	int choice(0);
	while (true)
	{
		system("cls");
		Console::firstscreen();
		choice = Console::choix(tab_menu_principal, Console::dim.X / 2 + 14, 20);
		switch (choice)
		{
		case 0:
			lancerPartie(5, 16);
			break;
		case 1:
			system("cls");
			Console::locate(Console::dim.X / 4, 22);
			cout << "Un projet de Marie-Anne Ferreira, Benjamin Jaulent, Malo Puissant, Julien Bonnet et Mehdi Lekouara" << endl;
			Console::locate(Console::dim.X / 2, 23);
			cout << "Comporte des surprises cachees" << endl;
			Console::locate(Console::dim.X / 2, 25);
			system("pause");
			break;
		case 2:
			exit(EXIT_SUCCESS);
		default:
			break;
		}
	}
}
