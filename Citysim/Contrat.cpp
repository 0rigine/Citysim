#include "stdafx.h"
#include "Contrat.h"

Contrat::Contrat()
{
}

Contrat::~Contrat()
{
	importatrice->endContract(this);
	exportatrice->endContract(this);
}