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
	auto engine = default_random_engine{};
	vector<vector<City*>> grille;
	vector<City*> towns;
	int u(0), v(0), len(sizex*sizey);
	towns.push_back(new Player());
	for (int i = 1; i < len; ++i) towns.push_back(new Autonomy());

	shuffle(towns.begin(), towns.end(), engine);

	grille.push_back(vector<City*>(0));
	for each (City* town in towns)
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
