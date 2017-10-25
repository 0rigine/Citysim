#pragma once
#include <string>
using namespace std;

class Faction
{
public:
	Faction();
	Faction(string arg_name);
	~Faction();

	// Somme des ressources
	void sum_nourriture(float arg_nourriture); // ajout nourriture � la faction
	void sum_energie(float arg_energie); // ajout energie � la faction
	void sum_budget(float arg_budget); // ajout budget � la faction

	// Achats / Vente
	void acheterVille(City & vendue, float prix = 10); // fonction d'achat de la ville

private:
	string name;
	float nourriture; // stock de nourriture
	float energie; // stock d'�nergie
	float budget; // argent disponible
};

