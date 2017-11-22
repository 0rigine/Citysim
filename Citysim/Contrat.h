#pragma once
#include "City.h"

class Contrat
{
public:
	// Constructeurs et destructeurs
	Contrat();
	Contrat(int duration, float arg_cost, City* import_to, float* import_resource, City* export_to, float* export_resource);

	~Contrat();

private:
	int timeLeft;
	float *resourceFrom;
	float *resourceTo;
	float cost;
	float quantity;
	bool statut;
	City* importatrice;
	City* exportatrice;
};
