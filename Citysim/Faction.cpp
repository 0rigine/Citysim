#include "stdafx.h"
#include <algorithm>
#include <thread>
using namespace std;
#include "Faction.h"

int Faction::factionNumber = 0;

Faction::Faction():
	budget(DEFAULT_WALLET),
	id(factionNumber)
{
	++factionNumber;
}

Faction::Faction(string arg_name, City* capitale):
	budget(DEFAULT_WALLET),
	id(factionNumber)
{
	name = arg_name;
	cities.push_back(capitale);
	++factionNumber;
}


Faction::~Faction()
{
}

void Faction::acheterVille(City *vendue, float prix)
{
	budget -= prix;
	vendue->getFaction()->vendreVille(vendue, prix);
	vendue->set_Faction(this);
	cities.push_back(vendue);
}

void Faction::vendreVille(City * vendue, float prix)
{
	cities.erase(remove(cities.begin(), cities.end(), vendue), cities.end());
	budget += prix;
}

void Faction::estimate()
{
	price = budget / cities.size();
}

bool Faction::canBuyIt(City* aVendre)
{
	if (aVendre->getPrice() <= budget) return true;
	return false;
}

bool Faction::canBuy()
{
	for each (City* town in getNeighbourhood())
	{
		if (canBuyIt(town)) return true;
	}
	return false;
}

const string Faction::getName() const
{
	return name;
}

const int Faction::getCitiesLenght() const
{
	return cities.size();
}

vector<City*> Faction::getNeighbourhood()
{
	vector<City*> neighbour;
	for each (City* town in cities)
	{
		for each (City* voisine in town->get_Neighbour())
		{
			neighbour.push_back(voisine);
		}
	}
	return neighbour;
}

float Faction::getBudget() const
{
	return budget;
}

float Faction::getPrice() const
{
	return price;
}

int Faction::getPopulation() const
{
	int totalPopulation(0);
	for each (City* town in cities)
	{
		totalPopulation += town->getPopulation();
	}
	return totalPopulation;
}

float Faction::getTempBudget() const
{
	return temporaryBudget;
}

mutex* Faction::getInSetting()
{
	return &inSetting;
}

void Faction::setBudget(float arg_budget)
{
	budget = arg_budget;
}

void Faction::budgetGrowing()
{
	float salaires(0);
	inSetting.lock();
	budget = 0;
	for each (City* town in cities)
	{
		salaires += town->salary();
		budget += town->production();
	}
	budget -= salaires;
	temporaryBudget = budget - salaires;
	inSetting.unlock();
}

void Faction::removeFromTemporaryBudget(float arg_temp)
{
	inSetting.lock();
	temporaryBudget -= arg_temp;
	inSetting.unlock();
}

void Faction::getVictory()
{

	for each (City* town in cities)
	{
		town->victory();
	}
}
