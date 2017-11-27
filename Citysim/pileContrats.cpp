#include "stdafx.h"
#include "pileContrats.h"


pileContrats::pileContrats():
	next(NULL),
	localContract(NULL)
{
}

pileContrats::pileContrats(Contrat * arg_contract, pileContrats * arg_next):
	next(arg_next),
	localContract(arg_contract)
{
}


pileContrats::~pileContrats()
{
}

void pileContrats::purge()
{
	if (next != NULL)
	{
		next->purge();
		if (next->isClosed()) removeNext();
	}
}

bool pileContrats::isClosed()
{
	return localContract->isClosed();
}

void pileContrats::removeNext()
{
	pileContrats *suivant(NULL);
	if (next != NULL)
	{
		suivant = next;
		next = next->getNext();
		delete suivant;
	}
}

pileContrats * pileContrats::getNext() const
{
	return next;
}
