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
	Grille game = Grille(sizex, sizey);
	game.playAGame();
}

void menu()
{
	const char* tab_menu_principal[] =
	{
		"Jouer",
		"Credit"
		"Quitter"
	};
	int choice(0);
	Console::firstscreen();
	choice = Console::choix(tab_menu_principal, 3, 80, 20);
	switch (choice)
	{
	case 0 :
		lancerPartie(5, 16);
		break;
	case 1:
		Console::locate(Console::dim.X / 2, 22);
		cout << "Merci a Marie - Anne Ferreira, Benjamin Jaulent, Malo Puissant, Julien Bonnet, et ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? a + " << endl;
		break;
	case 2:
		exit(EXIT_SUCCESS);
	default:
		break;
	}
}
