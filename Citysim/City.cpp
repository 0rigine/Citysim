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
	float consommation(20);
	float happyCoeff(happinessPart());
	energie = (float)energie+(energizer*coefficient*quantity*happyCoeff)+(energizer*coefficient*(1-happyCoeff))-population*consommation;
	return 0;
}

int City::foodGrowth()
{
	float coefficient(1); // coefficient bonus
	float quantity(30); // nourriture produite par habitant
	float consommation(10);
	float happyCoeff(happinessPart());
	// Production en fonction du bonheur de la population
	nourriture = (float)nourriture+(farmers*coefficient*quantity*happyCoeff)+(farmers*coefficient*(1-happyCoeff))-population*consommation;
	return 0;
}

int City::populationGrowth()
{
	float coefficient(1); // coefficient bonus
	float coeffSad(1 / 3); // coefficient de population malheureuse disparaissant
	int happy = happinessPart()*population; // habitants heureux
	int sad = population - happy;
	population = (int)(happy/2)-sad*coeffSad;
	return 0;
}

int City::happinessGrowth()
{

	return 0;
}

float City::happinessPart()
{
	float foodCons(10), energyCons(30), salaires(100);
	float happyFood = (nourriture / foodCons) / population;
	float happyEnergy = (energie / energyCons) / population;
	return happyFood*happyEnergy;
}
