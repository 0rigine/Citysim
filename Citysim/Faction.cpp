#include "stdafx.h"
#include <algorithm>
#include <thread>
using namespace std;
#include "Faction.h"

int Faction::factionNumber = 0;

Faction::Faction():
	budget(DEFAULT_WALLET),
	temporaryBudget(DEFAULT_WALLET),
	id(factionNumber)
{
	++factionNumber;
	colori = BASIC_COLOR;
}

Faction::Faction(string arg_name, City* capitale):
	budget(DEFAULT_WALLET),
	temporaryBudget(DEFAULT_WALLET),
	id(factionNumber)
{
	name = arg_name;
	cities.push_back(capitale);
	++factionNumber;
	colori = BASIC_COLOR;
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
	if (cities.size() > 1)
	{
		colori = 13;
	}
}

bool Faction::canBuyIt(City* aVendre)
{
	if (aVendre->getPrice() <= temporaryBudget) return true;
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

void Faction::resolveContract(float cost)
{
	budget += cost;
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
	for (vector<City*>::iterator it = neighbour.begin(); it != neighbour.end(); ++it)
	{
		neighbour.erase(remove(it+1, neighbour.end(), *it), neighbour.end());
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

mutex& Faction::getInSetting()
{
	return inSetting;
}

int Faction::getColori() const
{
	return colori;
}

void Faction::setBudget(float arg_budget)
{
	budget = arg_budget;
}

void Faction::budgetGrowing()
{
	float salaires(0);
	lock_guard<mutex> localLock(inSetting);
	budget = temporaryBudget;
	for each (City* town in cities)
	{
		salaires += town->realSalary();
		budget += town->production();
	}
	budget -= salaires;
	temporaryBudget = budget - salaires;
}

void Faction::removeFromTemporaryBudget(float arg_temp)
{
	temporaryBudget -= arg_temp;
}

void Faction::setColor(int arg_color)
{
	colori = arg_color;
}

void Faction::getVictory()
{

	for each (City* town in cities)
	{
		town->victory();
	}
}
