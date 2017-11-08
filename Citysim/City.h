#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <mutex>
using namespace std;

#include "RandomName.h"
#include "Skill.h"

// Définitions des retours d'erreurs
#define ATTRIBUTION_OK 0 // réussite d'attribution d'employés
#define ATTRIBUTION_ERROR 1 // erreur d'attribution d'employés

// Valeurs par défaut en début de partie
#define DEFAULT_POPULATION 100
#define DEFAULT_FOOD 10000
#define DEFAULT_ENERGY 20000
#define DEFAULT_WALLET 10000
#define DEFAULT_FARMERS 0
#define DEFAULT_TRADERS 0
#define DEFAULT_ENERGIZER 0

class Faction;

class City
{
public:
	static int cityNumber;
	// Constructeurs
	City();
	City(int arg_posx, int arg_posy);
	City(string name,
		int arg_posx,
		int arg_posy,
		float arg_bonheur = 1,
		int arg_population = DEFAULT_POPULATION,
		float arg_nourriture = DEFAULT_FOOD,
		float arg_energie = DEFAULT_ENERGY,
		float arg_budget = DEFAULT_WALLET);
	void initiate(int posx = 0, int posy = 0, string arg_name = RandomName::generate());
	// Destructeur
	virtual ~City();

	// Interface
	void presentation();
	virtual void working(); // affichage des employés
	virtual void turn() = 0; // tour de jeu

	// Croissance de la ville
	void growth(); // appel des fonctions de croissance
	void energyGrowth(float coeffHappy); // croissance de l'énergie
	void foodGrowth(float coeffHappy); // croissance de la nourriture
	void populationGrowth(float coeffHappy); // croissance de la population
	void happinessGrowth(float coeffHappy); // croissance du bonheur
	void budgetGrowth(); // croissance du budget

	// Estimations et mesures
	float happinessPart(); // Part de population heureuse (coefficient)

	// Gestion de la ville
	int set_Farmers(int toSet); // indiquer le nombre de fermiers actifs
	int set_Energize(int toSet); // indiquer le nombre de producteur d'énergie actifs
	int set_Traders(int toSet); // indiquer le nombre de traders actifs

	// Conquete
	void acheterVille(City *achetee, float prix = 10); // fonction d'achat d'une ville
	void propositionRachat(Faction *arg_acheteur, float proposition); // fonction de proposition d'achat de la ville
	virtual void achatFinTour(); // fonction de fin de tour pour le rachat de la ville
	void estimate(); // estimation du prix de la ville

	// Accesseurs
	const string getName() const; // Accesseur de nom
	Faction* getFaction() const; // Accesseur de faction
	vector<City*> get_Neighbour() const; // Accesseur de voisins 
	float getFood() const;
	float getEnergy() const;
	float getWallet() const;
	float getPrice() const; // Accesseur de prix de vente
	Faction* getAcheteur() const; // Accesseur d'acheteur

	// Setters
	void set_Coord(int posx, int posy); // setter de position
	void set_Map(vector<vector<City*>> *arg_map); // setter de la map
	void set_Faction(Faction *newFaction); // setter de la faction

	// Fin de partie
	virtual void victory() = 0;

private:
	
	// Attributes
	string nom; // nom de la ville
	Faction *faction; // faction de la ville
	int id; // id de la ville
	int coord_x; // coordonnée de la ville en x
	int coord_y; // coordonnée de la ville en y

	int population; // population totale
	int farmers; // fermiers
	int energizer; // producteurs d'énergie
	int traders; // employés dans la finance

	float nourriture; // stock de nourriture
	float energie; // stock d'énergie
	float budget; // argent disponible
	float bonheur; // bonheur accumulé

	mutex negocie;
	float prix; // prix minimum de la ville (estimé en début de tour)
	Faction* acheteur; // faction proposant le prix le plus élevé pour la ville

	vector< vector<City*> > *worldMap; // carte du monde (grille)


	/*
	Skill skillFood; // arbre de compétences : nourriture
	Skill skillEnergy; // arbre de compétences : énergie
	Skill skillEconomy; // arbre de compétences : économie
	*/
};
