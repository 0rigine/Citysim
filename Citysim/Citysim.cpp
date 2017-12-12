#include "stdafx.h"
#include <random>
#include <time.h>
#include <iostream>
using namespace std;
#include "Grille.h"
//#include "Display.h"


// PROTOTYPES
void lancerPartie(int sizex = 2, int sizey = 2); // lancement d'une partie


// PROGRAMME PRINCIPAL
int main()
{
	srand(time(NULL));
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
