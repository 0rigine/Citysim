#pragma once
#include "City.h"

class Contrat
{
public:
	// Constructeurs et destructeurs
	Contrat();
	~Contrat();

private:
	int timeLeft;
	float *resourceUsed;
	float cost;
	float quantity;
	City* importatrice;
	City* exportatrice;
};
