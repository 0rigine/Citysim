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

void pileContrats::removeAll(pileContrats** cur)
{
	if (next != NULL) next->removeAll(&next);
	delete this;
	*cur = NULL;
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

void pileContrats::removeThis(pileContrats** current, float arg_marchandises[][MERCHANDISES_LINES][MERCHANDISES_COLUMNS])
{
	if (localContract->isThat(arg_marchandises))
	{
		removeCurrent(current);
	}
}

void pileContrats::removeCurrent(pileContrats ** to_remove)
{
	if (*to_remove != this) return;
	if (next == NULL)
	{
		*to_remove = NULL;
	}
	else
	{
		*to_remove = next;
	}
	delete this;
}

void pileContrats::addNext(Contrat * arg_contrat)
{
	if (next != NULL)
	{
		next->addNext(arg_contrat);
	}
	else
	{
		next = new pileContrats(arg_contrat);
	}
}

bool pileContrats::isPresent(float arg_marchandises[][MERCHANDISES_LINES][MERCHANDISES_COLUMNS])
{
	bool temp(false);
	if (next != NULL) temp = next->isPresent(arg_marchandises);
	if (temp == false) return localContract->isThat(arg_marchandises);
	return true;
}

Contrat * pileContrats::findContract(float arg_marchandises[][MERCHANDISES_LINES][MERCHANDISES_COLUMNS])
{
	Contrat* temp(NULL);
	if (next != NULL) temp = next->findContract(arg_marchandises);
	if (temp == NULL && localContract->isThat(arg_marchandises)) return localContract;
	return temp;
}

pileContrats * pileContrats::getNext() const
{
	return next;
}
