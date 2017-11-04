#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


#include "Skill.h"

// Définitions des retours d'erreurs
#define ATTRIBUTION_OK 0 // réussite d'attribution d'employés
#define ATTRIBUTION_ERROR 1 // erreur d'attribution d'employés
class Faction;

class City
{
public:
	static int cityNumber;
	City();
	City(string name, float arg_bonheur = 0, int arg_population = 100, float arg_nourriture = 2000, float arg_energie = 10000, float arg_budget = 200000);
	virtual ~City();

	void presentation();
	virtual void turn() = 0;

	// Croissance de la ville
	int growth(); // appel des fonctions de croissance
	int energyGrowth(); // croissance de l'énergie
	int foodGrowth(); // croissance de la nourriture
	int populationGrowth(); // croissance de la population
	int happinessGrowth(); // croissance du bonheur
	int budgetGrowth(); // croissance du budget

	// Estimations et mesures
	float happinessPart(); // Part de population heureuse (coefficient)

	// Gestion de la ville
	int set_Farmers(int toSet); // indiquer le nombre de fermiers actifs
	int set_Energize(int toSet); // indiquer le nombre de producteur d'énergie actifs
	int set_Traders(int toSet); // indiquer le nombre de traders actifs

	// Conquete
	void estAchetee(Faction *newFaction); // fonction de vente de la ville
	void acheterVille(City *achetee, float prix = 10);

	// Accesseurs
	const string getName() const; // Accesseur de nom

private:
	
	// Attributes
	string nom; // nom de la ville
	Faction *faction; // faction de la ville
	int id; // id de la ville

	int population; // population totale
	int farmers; // fermiers
	int energizer; // producteurs d'énergie
	int traders; // employés dans la finance

	float nourriture; // stock de nourriture
	float energie; // stock d'énergie
	float budget; // argent disponible
	float bonheur; // bonheur accumulé

	/*
	Skill skillFood; // arbre de compétences : nourriture
	Skill skillEnergy; // arbre de compétences : énergie
	Skill skillEconomy; // arbre de compétences : économie
	Skill constructions; // // arbre de constructions de la ville (commisariat, caserne, mairie...)
	*/
};
