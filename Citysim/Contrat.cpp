#include "stdafx.h"
#include "Contrat.h"

Contrat::Contrat() :
	timeLeft(1),
	resourceTo(NULL),
	resourceFrom(NULL),
	cost(1),
	quantity(1),
	importatrice(NULL),
	exportatrice(NULL)
{
}

Contrat::Contrat(int duration, float arg_cost, City * import_to, float * import_resource, City * export_to, float * export_resource) :
	timeLeft(duration),
	cost(arg_cost),
	importatrice(import_to),
	resourceTo(import_resource),
	exportatrice(export_to),
	resourceFrom(export_resource)
{
}

Contrat::~Contrat()
{
}

void Contrat::resolveContract()
{
	if (!isClosed()) // si toujours en cours
	{
		importatrice->resolveContract(resourceTo, quantity, (-1)*cost);
		exportatrice->resolveContract(resourceFrom, (-1)*quantity, cost);
		--timeLeft;
	}
}

bool Contrat::isClosed()
{
	if (timeLeft > 0) return false;
	return true;
}
