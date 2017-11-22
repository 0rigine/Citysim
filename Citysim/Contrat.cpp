#include "stdafx.h"
#include "Contrat.h"

Contrat::Contrat():
	timeLeft(1),
	resourceTo(NULL),
	resourceFrom(NULL),
	cost(1),
	quantity(1),
	importatrice(NULL),
	exportatrice(NULL),
	statut(true)
{
}

Contrat::Contrat(int duration, float arg_cost, City * import_to, float * import_resource, City * export_to, float * export_resource):
	timeLeft(duration),
	cost(arg_cost),
	importatrice(import_to),
	resourceTo(import_resource),
	exportatrice(export_to),
	resourceFrom(export_resource),
	statut(true)
{
}

Contrat::~Contrat()
{
	importatrice->endContract(this);
	exportatrice->endContract(this);
}

void Contrat::resolveContract()
{
	if (statut) // si le contrat est ouvert, donc non lancé dans le tour
	{
		importatrice->resolveContract(resourceTo, quantity, (-1)*cost);
		exportatrice->resolveContract(resourceFrom, (-1)*quantity, cost);
		--timeLeft;
		statut = false;
	}
	else
	{
		statut = true;
	}
	if (timeLeft < 1)
	{
		delete this;
	}
}
