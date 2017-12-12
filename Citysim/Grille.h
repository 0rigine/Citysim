#pragma once
#include <vector>
#include <thread>
using namespace std;

#include "City.h"
#include "Faction.h"
#include "pileContrats.h"

#define GENERATION_OK 0
#define GENERATION_FAILED 1

/* Classe régissant le jeu */
class Grille
{
public:
	Grille();
	Grille(int sizex, int sizey);
	Grille(string playerName, float food, float energy, float wallet, int sizex, int sizey); // Création de partie avec ville du joueur personnalisée
	~Grille();

	// Gestion du jeu
	void afficherVilles(); // Affichage de toutes les villes
	void playATurn(); // Lancement du tour en cours
	void playAGame(); // Partie en cours
	void launchMulti(void (City::*function)());
	void addContract(Contrat *arg_accord);

	// Instanciation de la grille
	int initialize_Grid(int sizex, int sizey); // initialiser grille avec les villes aléatoires
	int initialize_Grid(int sizex, int sizey, string name, float food, float energy, float wallet); // surcharge pour personnaliser ville du joueur

	// Victoire
	bool isVictory(); // Fonction d'annonce de victoire
	bool isPlayable(); // Test de jouabilité

	// Affichage
	void print_map(int sizex, int sizey); // affichage de la map

	// Accesseurs
	vector<vector<City*>>* getMap();

private:
	vector<vector<City*>> grid;
	vector<City*> towns;
	vector<Faction*> factionsList;
	pileContrats* contractList;
};

void do_join(thread& process); // faire un join() sur le thread donné