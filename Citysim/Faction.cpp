#include "stdafx.h"
#include "Faction.h"


Faction::Faction():
	nourriture(0),
	energie(0),
	budget(0)
{
}

Faction::Faction(string arg_name):
	nourriture(0),
	energie(0),
	budget(0)
{
	name = arg_name;
}


Faction::~Faction()
{
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

void Faction::acheterVille(City & vendue, float prix)
{
	budget -= prix;
	vendue.estAchetee(this);
}
