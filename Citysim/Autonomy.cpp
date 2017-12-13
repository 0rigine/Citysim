#include "stdafx.h"
#include "Autonomy.h"

Autonomy::Autonomy():City::City()
{
}


Autonomy::~Autonomy()
{
}

void Autonomy::turn()
{
	set_Farmers(getPopulation()/3);
	set_Energize(getPopulation()/3);
	set_Traders(getPopulation()/3);
}

void Autonomy::gererAccords()
{
}

void Autonomy::victory()
{
}

void Autonomy::defeat()
{
}
