#include "stdafx.h"
#include <random>
#include <time.h>
#include <iostream>
using namespace std;
#include "Grille.h"
#include "Display.h"


// PROTOTYPES
void lancerPartie(int sizex = 2, int sizey = 2); // lancement d'une partie


// PROGRAMME PRINCIPAL
int main()
{
	srand(time(NULL));

	adjustWindowSize();
	Firstscreen();
	const char* tab_menu_principale[] = { "Jouer","Credit","Quitter" };
	const char* tab_actions[] = { "Racheter une ville","Inspecter","Modification des ressources","Contrats","Fin du tour" };
	int c = choix(tab_menu_principale, 3, 80, 20);
	int d = 0;
	int x_choice = 0, y_choice = 0;
	int x_search = 0, y_search = 0;

	lancerPartie(5, 16);

	system("pause");
    return 0;
}

// DEFINITIONS
void lancerPartie(int sizex, int sizey)
{
	Grille game = Grille(sizex, sizey);
	game.playAGame();
}
