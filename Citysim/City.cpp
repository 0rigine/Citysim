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
	return 0;
}

int City::foodGrowth()
{
	return 0;
}

int City::populationGrowth()
{
	return 0;
}

int City::happinessGrowth()
{
	return 0;
}
