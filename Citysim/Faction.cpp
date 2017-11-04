#include "stdafx.h"
#include "Faction.h"
#include <algorithm>
using namespace std;

int Faction::factionNumber = 0;

Faction::Faction():
	nourriture(0),
	energie(0),
	budget(0),
	id(factionNumber)
{
	++factionNumber;
}

Faction::Faction(string arg_name):
	nourriture(0),
	energie(0),
	budget(0),
	id(factionNumber)
{
	name = arg_name;
	++factionNumber;
}


Faction::~Faction()
{
}

void Faction::update()
{
	for each (City* town in cities)
	{

	}
}

void Faction::sum_nourriture(float arg_nourriture)
{
}

void Faction::sum_energie(float arg_energie)
{
}

void Faction::sum_budget(float arg_budget)
{
}

void Faction::acheterVille(City *vendue, float prix)
{
	budget -= prix;
	vendue->estAchetee(this);
	cities.push_back(vendue);
}

void Faction::vendreVille(City * vendue, float prix)
{
	cities.erase(remove(cities.begin(), cities.end(), vendue), cities.end());
	budget += prix;
}
