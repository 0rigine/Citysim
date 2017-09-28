#pragma once
#include "City.h"
#include <vector>
using namespace std;

class Grille
{
public:
	Grille();
	~Grille();

	// Instanciation de la grille
	static vector<vector<City>> initialize_Grid(int sizex, int sizey);
};

