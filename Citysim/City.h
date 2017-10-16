#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#include "Tree.h"
#include "Skill.h"


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

	// Estimations et mesures
	float happinessPart(); // Part de population heureuse (coefficient)


private:
	// Attributes
	string nom;
	string faction;
	int id;
	int population;
	int farmers;
	int energizer;
	int traders;
	float nourriture;
	float energie;
	float budget;
	float bonheur;
	Tree<Skill> skillFood;
	Tree<Skill> skillEnergy;
	Tree<Skill> skillEconomy;
	Tree<Skill> constructions;
	//map<City*, Contrat> dealList;
};
