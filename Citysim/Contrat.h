#pragma once

#define MERCHANDISES_LINES 3
#define MERCHANDISES_COLUMNS 3

class City;

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

	// Tests
	bool isThat(float arg_marchandises[][MERCHANDISES_LINES][MERCHANDISES_COLUMNS]); // retourne true si le contrat correspond au tableau de transactions indiqué

private:
	int timeLeft;
	float marchandises[3][3]; /* grille de contrat :
							  - nourriture négociée
							  - energie
							  - cout */
	City* villeA;
	City* villeB;
};
