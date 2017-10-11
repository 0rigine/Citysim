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
	energie = (float)(energizer*coefficient*quantity);
	return 0;
}

int City::foodGrowth()
{
	float coefficient(1); // coefficient bonus
	float quantity(30); // nourriture produite par habitant
	nourriture = (float)(farmers*coefficient*quantity);
	return 0;
}

int City::populationGrowth()
{
	float coefficient(1); // coefficient bonus
	float happy(0); // habitants heureux
	population = (int)((population) / 2);
	return 0;
}

int City::happinessGrowth()
{

	return 0;
}

float City::happinessPart()
{
	float happy(0);
	float foodCons(10), energyCons(30), salaires(100);
	happy = (float)((population - (nourriture / foodCons)); // WIP
	return 0.0f;
}
