#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Tree.h"
#include "structures.h"
using namespace std;

class City
{
public:
	City();
	~City();

	// Contrats
	int parcourirContrats(); // renvoie une erreur au besoin
	int makeADeal(City associate, int timeleft, float &resourceUsed, float cost, float quantity); // création d'une structure contrat ajoutée à la liste de la ville active
	bool endADeal(contrat deal); // supprime le contrat indiqué
	bool honorTheDeal();


protected:
	// Attributes
	string nom;
	string faction;
	int id;
	int population;
	float alimentation;
	float energie;
	float budget;
	//Tree<UNKNOWN> competences;
	//Tree<UNKNOWN> constructions;
	vector<contrat> dealList;
};
