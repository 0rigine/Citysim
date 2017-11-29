#include "stdafx.h"
#include "Contrat.h"

Contrat::Contrat() :
	timeLeft(1),
	villeA(NULL),
	villeB(NULL)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			marchandises[i][j] = 0;
		}
	}
}

Contrat::Contrat(int duration, float arg_cost, City* desserve, City* client, float food, float energia):
	timeLeft(duration),
	villeA(desserve),
	villeB(client)
{
	marchandises[0][1] = food;
	if (food < 0)
	{
		marchandises[0][0] = -1;
		marchandises[0][2] = 1;
	}
	else
	{
		marchandises[0][0] = 1;
		marchandises[0][2] = -1;
	}
	marchandises[1][1] = energia;
	if (energia < 0)
	{
		marchandises[1][0] = -1;
		marchandises[1][2] = 1;
	}
	else
	{
		marchandises[1][0] = 1;
		marchandises[1][2] = -1;
	}
	marchandises[2][1] = arg_cost;
	if (arg_cost < 0)
	{
		marchandises[2][0] = -1;
		marchandises[2][2] = 1;
	}
	else
	{
		marchandises[2][0] = 1;
		marchandises[2][2] = -1;
	}
}

Contrat::~Contrat()
{
}

void Contrat::resolveContract()
{
	if (!isClosed()) // si toujours en cours
	{
		villeA->resolveContract(marchandises[0][0] * marchandises[0][1],
			marchandises[1][0] * marchandises[1][1],
			marchandises[2][0] * marchandises[2][1]);
		villeB->resolveContract(marchandises[0][2] * marchandises[0][1],
			marchandises[1][2] * marchandises[1][1],
			marchandises[2][2] * marchandises[2][1]);
		--timeLeft;
	}
}

bool Contrat::isClosed()
{
	if (timeLeft > 0) return false;
	return true;
}
