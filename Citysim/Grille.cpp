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
	initialize_Grid(2, 2); // initialisation d'une grille avec une taille de 2x2 par d�faut
}

Grille::Grille(int sizex, int sizey)
{
	initialize_Grid(sizex, sizey);
}


Grille::~Grille()
{
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

	// Estimations des prix des villes
	for each (City *town in towns)
	{
		processus.push_back(thread(&City::estimate, town));
	}
	for_each(processus.begin(), processus.end(), do_join);

	processus.clear();

	// Tour de jeu
	for each (City *town in towns)
	{
		processus.push_back(thread(&City::turn,town));
	}
	for_each(processus.begin(), processus.end(), do_join);

	processus.clear();

	// R�solution des achats de villes
	for each (City *town in towns)
	{
		processus.push_back(thread(&City::achatFinTour, town));
	}
	for_each(processus.begin(), processus.end(), do_join);

	processus.clear();

	// Mise � jour des ressources de faction
	for each (Faction *group in factionsList)
	{
		if (group->getCitiesLenght() > 0)
		{
			processus.push_back(thread(&Faction::update, group));
		}
		else
		{
			toDelete.push_back(group);
		}
	}
	for_each(processus.begin(), processus.end(), do_join);

	// Suppression des factions �limin�es
	for (vector<Faction*>::iterator it = toDelete.begin(); it != toDelete.end(); ++it)
	{
		factionsList.erase(remove(factionsList.begin(), factionsList.end(), *it), factionsList.end());
		delete *it;
	}
	
}

void Grille::playAGame()
{
	while (!isVictory())
	{
		playATurn();
	}
}

int Grille::initialize_Grid(int sizex, int sizey)
{
	int row(0), column(0), len(sizex*sizey); // colonnes et lignes pour la taille limite ainsi que le nombre de villes devant �tre cr��es
	towns.push_back(new Player()); // on cr�e la ville du joueur
	for (int i = 1; i < len; ++i) towns.push_back(new Autonomy()); // on ajoute � la liste les villes IA

	random_shuffle(towns.begin(), towns.end()); // on m�lange la liste des villes

	grid.push_back(vector<City*>(0));
	for each (City* town in towns) // on distribue dans la grille la liste, leur position est al�atoire
	{
		factionsList.push_back(town->getFaction()); // ajout de la faction � la liste des factions pr�sentes
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
	int lenght(factionsList.size());
	if (lenght == 1)
	{
		factionsList.front()->getVictory();
		return true;
	}
	return false;
}
