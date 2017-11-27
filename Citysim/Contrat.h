#pragma once
#include "City.h"

class Contrat
{
public:
	// Constructeurs et destructeurs
	Contrat();
	Contrat(int duration, float arg_cost, City* import_to, float* import_resource, City* export_to, float* export_resource); // création complète d'un contrat

	~Contrat();

	// Application des contrats
	void resolveContract(); // résolution du contrat

	bool isClosed(); // tester si le contrat est terminé

private:
	int timeLeft;
	float *resourceFrom;
	float *resourceTo;
	float cost;
	float quantity;
	City* importatrice;
	City* exportatrice;
};
