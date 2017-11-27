#pragma once
#include "Liste.h"

class Contrat;

class pileContrats
{
public:
	pileContrats();
	~pileContrats();

private:
	Liste< Contrat* > contractsList; // liste des contrats
};