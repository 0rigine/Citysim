#include "stdafx.h"
#include "Grille.h"
#include <random>
#include <algorithm>
#include <thread>
using namespace std;

#include "Player.h"
#include "Autonomy.h"
#include "Faction.h"
#include "Display.h"

Grille::Grille():
	contractList(NULL),
	dim_x(DEFAULT_X),
	dim_y(DEFAULT_Y)
{
	initialize_Grid(); // initialisation d'une grille avec une taille de 2x2 par défaut
}

Grille::Grille(int sizex, int sizey):
	contractList(NULL),
	dim_x(sizex),
	dim_y(sizey)
{
	initialize_Grid(sizex, sizey);
}

Grille::Grille(string playerName, float food, float energy, float wallet, int sizex, int sizey):
	contractList(NULL),
	dim_x(sizex),
	dim_y(sizey)
{
	initialize_Grid(sizex,sizey,playerName,food,energy,wallet);
}


Grille::~Grille()
{
	for each(City* town in towns) delete town;
	for each(Faction* group in factionsList) delete group;
	if (contractList != NULL) contractList->removeAll(&contractList);
}

void Grille::afficherVilles()
{
	vector<vector<City*>>::iterator it;
	vector<City*>::iterator jt;
	int x(2), y(2);
	for (it = grid.begin(); it != grid.end(); it++)
	{
		for (jt = it->begin(); jt != it->end(); jt++)
		{
			(*jt)->drawMyBuilding(x,y);
			x += 6;
		}
		x = 2;
		y += 4;
	}
	Console::locate(0, y);
	for (int i = 0; i < Console::dim.X*2/3+20; i++) cout << "-";
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

	// Tour de jeu
	launchMulti(&City::turn);

	// Croissance
	launchMulti(&City::growth);

	// Résolution des achats de villes
	launchMulti(&City::achatFinTour);

	// Signature des contrats
	launchMulti(&City::gererAccords);

	// Résolution des contrats
	if (contractList != NULL)
	{
		contractList->resolveAll();
		contractList->purge(&contractList);
	}

	// Mise à jour des factions encore en jeu
	for each(Faction* group in factionsList)
	{
		if (group->getCitiesLenght() == 0)
		{
			toDelete.push_back(group);
		}
	}

	// Suppression des factions éliminées
	for (vector<Faction*>::iterator it = toDelete.begin(); it != toDelete.end(); it++)
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

void Grille::addContract(Contrat * arg_accord)
{
	if (contractList != NULL) contractList->addNext(arg_accord);
	else contractList = new pileContrats(arg_accord);
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
		town->set_Game(this);
		grid[row].push_back(town);
		++column;
	}

	return GENERATION_OK;
}

int Grille::initialize_Grid(int sizex, int sizey, string name, float food, float energy, float wallet)
{
	int row(0), column(0), len(sizex*sizey); // colonnes et lignes pour la taille limite ainsi que le nombre de villes devant être créées
	towns.push_back(new Player(name,food,energy,wallet)); // on crée la ville du joueur
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
		town->set_Game(this);
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

vector<vector<City*>>* Grille::getMap()
{
	return &grid;
}

City * Grille::getCityAt(int x, int y)
{
	vector<vector<City*>>::iterator i(grid.begin()+x);
	vector<City*>::iterator j((*i).begin() + y);
	return *j;
}

int Grille::numberContractsByCity(City * ville)
{
	if(contractList != NULL) return contractList->numberByCity(ville);
	return 0;
}

int Grille::getDim_x() const
{
	return dim_x;
}

int Grille::getDim_y() const
{
	return dim_y;
}
