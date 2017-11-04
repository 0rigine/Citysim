#include "stdafx.h"
#include "Grille.h"
#include <random>
#include <algorithm>
using namespace std;
#include "Player.h"
#include "Autonomy.h"

Grille::Grille()
{
}


Grille::~Grille()
{
}

vector<vector<City*>> Grille::initialize_Grid(int sizex, int sizey)
{
	vector<vector<City*>> grille;
	vector<City*> towns;
	int u(0), v(0), len(sizex*sizey); // colonnes et lignes pour la taille limite ainsi que le nombre de villes devant �tre cr��es
	towns.push_back(new Player()); // on cr�e la ville du joueur
	for (int i = 1; i < len; ++i) towns.push_back(new Autonomy()); // on ajoute � la liste les villes IA

	random_shuffle(towns.begin(), towns.end()); // on m�lange la liste des villes

	grille.push_back(vector<City*>(0));
	for each (City* town in towns) // on distribue dans la grille la liste, leur position est al�atoire
	{
		if (v == sizey)
		{
			++u;
			v = 0;
			grille.push_back(vector<City*>(0));
		}
		grille[u].push_back(town);
		++v;
	}

	return grille;
}
