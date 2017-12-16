#include "stdafx.h"
#include "Autonomy.h"
#include "Faction.h"

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
	buy();
}

void Autonomy::buy()
{
	int i(0);
	int choice(0);
	int size(0);
	float price(0); // prix d'achat proposé
	vector<City*> voisines;
	vector<City*> toBuy;
	City* villeAchetee(NULL);
	if (getFaction()->canBuy())
	{
		voisines = getFaction()->getNeighbourhood();
		price = (*voisines.begin())->getPrice() + 1;
		villeAchetee = (*voisines.begin());
		for each (City* town in voisines)
		{
			if (getFaction()->canBuyIt(town))
			{
				toBuy.push_back(town);
				if (town->getPrice() < price)
				{
					price = town->getPrice() + 1;
					villeAchetee = town;
				}
			}
		}
		acheterVille(villeAchetee, price);
	}
}

void Autonomy::gererAccords()
{
	//vector<vector<vector<float>>> contratsProposes(neighboorContracts());

}

void Autonomy::victory()
{
}

void Autonomy::defeat()
{
}
