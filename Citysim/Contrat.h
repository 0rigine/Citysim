#pragma once
#include <vector>

using namespace std;

#define MERCHANDISES_LINES 3
#define MERCHANDISES_COLUMNS 3

class City;

class Contrat
{
public:
	// Constructeurs et destructeurs
	Contrat();
	Contrat(int duration, float arg_cost, City* desserve, City* client, float food, float energia); // cr�ation compl�te d'un contrat

	~Contrat();

	// Application des contrats
	void resolveContract(); // r�solution du contrat
	bool isClosed(); // tester si le contrat est termin�

	// Configuration
	void set_client(City* client); // configurer le client

	// Tests
	bool isThat(float arg_marchandises[][MERCHANDISES_LINES][MERCHANDISES_COLUMNS]); // retourne true si le contrat correspond au tableau de transactions indiqu�

	// Pr�sentation
	vector<vector<float>> presentate(); // retourne une copie de marchandises

private:
	int timeLeft;
	float marchandises[3][3]; /* grille de contrat :
							  - nourriture n�goci�e
							  - energie
							  - cout */
	City* villeA;
	City* villeB;
};
