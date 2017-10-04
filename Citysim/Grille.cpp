#include "stdafx.h"
#include "Grille.h"


Grille::Grille()
{
}


Grille::~Grille()
{
}

vector<vector<City>> Grille::initialize_Grid(int sizex, int sizey)
{
	vector<vector<City>> grille;
	for (int i = 0; i < sizex; i++)
	{
		grille.push_back(vector<City>(sizey));
		for (int j = 0; j < sizey; j++)
		{
			grille[i][j] = City();
		}
	}

	return grille;
}
