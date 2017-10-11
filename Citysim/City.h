#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#include "Tree.h"

#define UNKNOWN int

class City
{
public:
	City();
	~City();

	int simulate(); // fonction de routine, simulant l'évolution de la ville
	// Contrats
	/*
	int parcourirContrats(); // renvoie une erreur au besoin
	int makeADeal(City *associate, int timeleft, float &resourceUsed, float cost, float quantity); // création d'une structure contrat ajoutée à la liste de la ville active
	bool endADeal(City *associate); // supprime le contrat indiqué
	bool honorTheDeal(City *associate, Contrat &deal); // honorer le contrat
	*/

	// Croissance de la ville
	int growth();
	int energyGrowth();
	int foodGrowth();
	int populationGrowth();
	int happinessGrowth();


private:
	// Attributes
	string nom;
	string faction;
	int id;
	int population;
	float alimentation;
	float energie;
	float budget;
	float bonheur;
	Tree<UNKNOWN> skillFood;
	Tree<UNKNOWN> skillEnergy;
	Tree<UNKNOWN> skillEconomy;
	Tree<UNKNOWN> constructions;
	//map<City*, Contrat> dealList;
};
