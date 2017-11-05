#pragma once
#include "City.h"
#include "Faction.h"
#include <vector>
#include <thread>
using namespace std;

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
	void afficherVilles();
	void playATurn();

	// Instanciation de la grille
	int initialize_Grid(int sizex, int sizey);

private:
	vector<vector<City*>> grid;
	vector<City*> towns;
	vector<Faction*> factionsList;
};

void do_join(thread& process);