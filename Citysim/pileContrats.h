#pragma once
#include "Contrat.h"

class pileContrats: Contrat
{
public:
	pileContrats();
	~pileContrats();

private:
	pileContrats *next;
};