#include "stdafx.h"
#include "Grille.h"
#include <random>
#include <algorithm>
#include <thread>
using namespace std;
#include "Player.h"
#include "Autonomy.h"
#include "Faction.h"

Grille::Grille()
{
	initialize_Grid(2, 2); // initialisation d'une grille avec une taille de 2x2 par défaut
}

Grille::Grille(int sizex, int sizey)
{
	initialize_Grid(sizex, sizey);
}


Grille::~Grille()
{
	for each(City* town in towns) delete town;
	for each(Faction* group in factionsList) delete group;
}

void Grille::afficherVilles()
{
	vector<vector<City*>>::iterator it;
	vector<City*>::iterator jt;
	for (it = grid.begin(); it != grid.end(); ++it)
	{
		for (jt = it->begin(); jt != it->end(); ++jt)
		{
			(*jt)->presentation();
		}
	}
}

void do_join(thread& process)
{
	process.join();
}

void Grille::playATurn()
{
	vector<thread> processus;
	vector<Faction*> toDelete;

	// Mise à jour des prix de villes de faction
	for each (Faction *group in factionsList)
	{
		if (group->getCitiesLenght() > 0)
		{
			processus.push_back(thread(&Faction::estimate, group));
			processus.push_back(thread(&Faction::budgetGrowing, group));
		}
		else
		{
			toDelete.push_back(group);
		}
	}
	for_each(processus.begin(), processus.end(), do_join);
	processus.clear();

	// Estimations des prix des villes
	launchMulti(&City::estimate);

	afficherVilles();
	system("pause & cls");

	// Tour de jeu
	launchMulti(&City::turn);

	// Croissance
	launchMulti(&City::growth);

	// Résolution des achats de villes
	launchMulti(&City::achatFinTour);

	// Suppression des factions éliminées
	for (vector<Faction*>::iterator it = toDelete.begin(); it != toDelete.end(); ++it)
	{
		factionsList.erase(remove(factionsList.begin(), factionsList.end(), *it), factionsList.end());
		delete *it;
	}
}

void Grille::playAGame()
{
	bool victory(false);
	while (!victory)
	{
		playATurn();
		// Vérification de la situation des villes
		if (!isPlayable()) 
		{
			launchMulti(&City::defeat);
			return;
		}
		victory = isVictory();
	}
}

void Grille::launchMulti(void(City::*function)())
{
	vector<thread> processus;
	for each (City *town in towns)
	{
		processus.push_back(thread(function, town));
	}
	for_each(processus.begin(), processus.end(), do_join);
}

int Grille::initialize_Grid(int sizex, int sizey)
{
	int row(0), column(0), len(sizex*sizey); // colonnes et lignes pour la taille limite ainsi que le nombre de villes devant être créées
	towns.push_back(new Player()); // on crée la ville du joueur
	for (int i = 1; i < len; ++i) towns.push_back(new Autonomy()); // on ajoute à la liste les villes IA

	random_shuffle(towns.begin(), towns.end()); // on mélange la liste des villes

	grid.push_back(vector<City*>(0));
	for each (City* town in towns) // on distribue dans la grille la liste, leur position est aléatoire
	{
		factionsList.push_back(town->getFaction()); // ajout de la faction à la liste des factions présentes
		if (column == sizey)
		{
			++row;
			column = 0;
			grid.push_back(vector<City*>(0));
		}
		town->set_Coord(row, column);
		town->set_Map(&grid);
		grid[row].push_back(town);
		++column;
	}

	return GENERATION_OK;
}

bool Grille::isVictory()
{
	int length(factionsList.size());
	if (length == 1)
	{
		factionsList.front()->getVictory();
		return true;
	}
	return false;
}

bool Grille::isPlayable()
{
	int cityOK(0); // villes susceptibles d'évoluer
	for each (Faction *group in factionsList)
	{
		if (group->getPopulation() > 0) ++cityOK;
	}
	if (cityOK > 0) return true;
	return false;
}
