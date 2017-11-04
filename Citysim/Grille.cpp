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
	vector<vector<City*>>::iterator i;
	vector<City*>::iterator j;
	for (i = grille.begin(); i != grille.end(); ++i)
	{
		grille.push_back(vector<City*>(0));
		for (j = i->begin(); j != i->end(); ++j)
		{
			i->push_back(new City());
		}
	}

	return grille;
}
