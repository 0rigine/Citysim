#pragma once
#include <vector>
#include <thread>
using namespace std;
#include "City.h"
#include "Faction.h"

#define GENERATION_OK 0
#define GENERATION_FAILED 1

/* Classe régissant le jeu */
class Grille
{
public:
	Grille();
	Grille(int sizex, int sizey);
	~Grille();

	// Gestion du jeu
	void afficherVilles(); // Affichage de toutes les villes
	void playATurn(); // Lancement du tour en cours
	void playAGame(); // Partie en cours
	void launchMulti(void (City::*function)());

	// Instanciation de la grille
	int initialize_Grid(int sizex, int sizey);

	// Victoire
	bool isVictory(); // Fonction d'annonce de victoire
	bool isPlayable(); // Test de jouabilité

private:
	vector<vector<City*>> grid;
	vector<City*> towns;
	vector<Faction*> factionsList;
};

void do_join(thread& process); // faire un join() sur le thread donné
