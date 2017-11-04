#include "stdafx.h"
#include "Grille.h"
#include <random>
#include <algorithm>
using namespace std;

Grille::Grille()
{
}


Grille::~Grille()
{
}

vector<vector<City*>> Grille::initialize_Grid(int sizex, int sizey)
{
	vector<vector<City*>> grille;
	for (int i = 0; i < sizex ; ++i)
	{
		grille.push_back(vector<City*>(0));
		for (int j = 0; j < sizey; ++j)
		{
			grille[i].push_back(new City());
		}
	}

	return grille;
}
