#pragma once
#include "City.h"

class Contrat
{
public:
	// Constructeurs et destructeurs
	Contrat();
	Contrat(int duration, float arg_cost, City* desserve, City* client, float food, float energia); // création complète d'un contrat

	~Contrat();

	// Application des contrats
	void resolveContract(); // résolution du contrat

	bool isClosed(); // tester si le contrat est terminé

private:
	int timeLeft;
	float marchandises[3][3]; /* grille de contrat :
							  - nourriture négociée
							  - energie
							  - cout */
	City* villeA;
	City* villeB;
};
