#include "stdafx.h"
#include "City.h"
#include <thread>
using namespace std;

City::City()
{
}


City::~City()
{
}

int City::simulate()
{
	return 0;
}

int City::growth()
{
	while (true)
	{
		energyGrowth();
		foodGrowth();
		happinessGrowth();
		populationGrowth();
		this_thread::sleep_for(3s);
	}
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
	float coeffSad(1 / 3); // coefficient de population malheureuse disparaissant
	int happy(happinessPart()*population); // habitants heureux
	int sad(population - happy); // population dont les besoins ne sont pas tous satisfaits
	population = (int)(happy/2)-sad*coeffSad; // population restante
	return 0;
}

int City::happinessGrowth()
{
	float coefficient(1); // coefficient bonus
	int happynessPop(happinessPart()*population); // population comblee
	bonheur = bonheur + (happynessPop*coefficient) - (population - happynessPop)*coefficient; // calcul du bonheur selon la population heureuse et malheureuse
	return 0;
}

float City::happinessPart()
{
	float foodCons(10), energyCons(30), salaires(100); // besoins par habitant selon la ressource
	float happyFood = (nourriture / foodCons) / population; // part de population dont les besoins en nourriture sont satisfaits
	float happyEnergy = (energie / energyCons) / population; // part de population dont les besoins en energie sont satisfaits
	return happyFood*happyEnergy; // part de population dont tous les besoins sont satisfaits
}

int set_Farmers(int toSet)
{
	int freePopulation(population-energizer-traders);
	int maximum(skillFood.ceil());
	if(toSet < 0 || toSet > maximum || toSet > freePopulation) return ATTRIBUTION_ERROR;
	farmers = toSet;
	return ATTRIBUTION_OK;
}

int set_Energize(int toSet)
{
	int freePopulation(population-farmers-traders);
	int maximum(skillEnergy.ceil());
	if(toSet < 0 || toSet > maximum || toSet > freePopulation) return ATTRIBUTION_ERROR;
	energizer = toSet;
	return ATTRIBUTION_OK;
}

int set_Traders(int toSet)
{
	int freePopulation(population-farmers-energizer);
	int maximum(skillEconomy.ceil());
	if(toSet < 0 || toSet > maximum || toSet > freePopulation) return ATTRIBUTION_ERROR;
	traders = toSet;
	return ATTRIBUTION_OK;
}
