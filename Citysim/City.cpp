#include "stdafx.h"

#include "Faction.h"
#include "City.h"
#include "RandomName.h"
#include <iostream>
using namespace std;

int City::cityNumber = 0;


City::City():
	bonheur(0),
	population(100),
	nourriture(2000),
	energie(10000),
	budget(200000),
	farmers(0),
	energizer(0),
	traders(0)
{
	nom = RandomName::generate();
	faction = new Faction(nom, this);
	id = City::cityNumber;
	++City::cityNumber;


}

City::City(string name, float arg_bonheur, int arg_population, float arg_nourriture, float arg_energie, float arg_budget):
	bonheur(0),
	population(100),
	nourriture(2000),
	energie(10000),
	budget(200000),
	farmers(0),
	energizer(0),
	traders(0)
{
	id = City::cityNumber;
	++City::cityNumber;
	nom = name;
	faction = new Faction(nom, this);
	population = arg_population;
	nourriture = arg_nourriture;
	energie = arg_energie;
	budget = arg_budget;
	bonheur = arg_bonheur;
}


City::~City()
{
}

void City::presentation()
{
	cout << nom << " abrite " << population << " habitants" << endl;
}

int City::growth()
{
	energyGrowth();
	foodGrowth();
	happinessGrowth();
	populationGrowth();
	budgetGrowth();
	return 0;
}

int City::energyGrowth()
{
	float coefficient(1); // coefficient bonus
	float quantity(50); // energie produite par habitant
	float consommation(20); // energie consommee par habitant
	float happyCoeff(happinessPart()); // part de population heureuse
	// Production en fonction du bonheur de la population
	energie = (float)energie+(energizer*coefficient*quantity*happyCoeff)+(energizer*coefficient*(1-happyCoeff))-population*consommation;
	return 0;
}

int City::foodGrowth()
{
	float coefficient(1); // coefficient bonus
	float quantity(30); // nourriture produite par habitant
	float consommation(10); // nourriture consommee par habitant
	float happyCoeff(happinessPart()); // part de population heureuse
	// Production en fonction du bonheur de la population
	nourriture = (float)nourriture+(farmers*coefficient*quantity*happyCoeff)+(farmers*coefficient*(1-happyCoeff))-population*consommation;
	return 0;
}

int City::populationGrowth()
{
	float coefficient(1); // coefficient bonus
	float coeffSad(1 / bonheur); // coefficient de population malheureuse disparaissant
	float coeffWorker(1);
	int newPopulation(0),travailleurs(0);
	int happy(happinessPart()*population); // habitants heureux
	int sad(population - happy); // population dont les besoins ne sont pas tous satisfaits
	newPopulation = (int)population+(happy/2)-sad*coeffSad; // population restante
	travailleurs = farmers + energizer + traders;
	if (travailleurs > newPopulation)
	{
		coeffWorker = (travailleurs - newPopulation) / newPopulation;
		energizer *= coeffWorker;
		farmers *= coeffWorker;
		traders *= coeffWorker;
	}
	return 0;
}

int City::happinessGrowth()
{
	float coefficient(1); // coefficient bonus
	int happynessPop(happinessPart()*population); // population comblee
	bonheur = bonheur + (happynessPop*coefficient) - (population - happynessPop)*coefficient; // calcul du bonheur selon la population heureuse et malheureuse
	return 0;
}

int City::budgetGrowth()
{
	float salaire(2.5),coeffTraders(20.5);
	int travailleurs = farmers + energizer + traders;
	budget = budget + traders*coeffTraders - salaire*travailleurs;
	return 0;
}

float City::happinessPart()
{
	float foodCons(10), energyCons(30); // besoins par habitant selon la ressource
	float happyFood = (nourriture / foodCons) / population; // part de population dont les besoins en nourriture sont satisfaits
	float happyEnergy = (energie / energyCons) / population; // part de population dont les besoins en energie sont satisfaits
	return happyFood*happyEnergy; // part de population dont tous les besoins sont satisfaits
}

void City::estAchetee(Faction *newFaction)
{
	faction = newFaction;
}

void City::acheterVille(City *achetee, float prix)
{
	faction->acheterVille(achetee, prix);
}

int City::set_Farmers(int toSet)
{
	int freePopulation(population-energizer-traders);
	int maximum(100);
	if(toSet < 0 || toSet > maximum || toSet > freePopulation) return ATTRIBUTION_ERROR;
	farmers = toSet;
	return ATTRIBUTION_OK;
}

int City::set_Energize(int toSet)
{
	int freePopulation(population-farmers-traders);
	int maximum(100);
	if(toSet < 0 || toSet > maximum || toSet > freePopulation) return ATTRIBUTION_ERROR;
	energizer = toSet;
	return ATTRIBUTION_OK;
}

int City::set_Traders(int toSet)
{
	int freePopulation(population-farmers-energizer);
	int maximum(100);
	if(toSet < 0 || toSet > maximum || toSet > freePopulation) return ATTRIBUTION_ERROR;
	traders = toSet;
	return ATTRIBUTION_OK;
}