#pragma once
#include <string>
#include <vector>
#include <mutex>
using namespace std;

#include "City.h"

class Faction
{
public:
	Faction();
	Faction(string arg_name, City* capitale);
	~Faction();

	// Achats / Vente
	void acheterVille(City *vendue, float prix = 10); // fonction d'achat de la ville
	void vendreVille(City *vendue, float prix = 10); // fonction de vente d'une ville
	void estimate(); // estimation du prix des villes de la faction

	// Accesseurs
	const string getName() const; // Accesseur de name
	const int getCitiesLenght() const; // Accesseur de la longueur de cities
	vector<City*> getNeighbourhood(); // Liste des villes voisines de la faction
	float getBudget() const; // Accesseur du budget
	float getPrice() const; // Accesseur du prix
	int getPopulation() const; // Calculateur du total de population

	// Setters
	void setBudget(float arg_budget); // setter de budget
	void budgetGrowing(City* setBy); // Croissance du budget

	// Victoire
	void getVictory(); // Victoire

private:
	static int factionNumber;
	string name;
	int id;
	float budget; // argent disponible
	float price;
	vector<City*> cities;
	mutex inSetting;
};

