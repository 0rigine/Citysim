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
	bool canBuyIt(City* aVendre); // tester l'achat de la ville
	bool canBuy(); // vérifier s'il est possible d'acheter une ville voisine
	void allowedBudget(); // calcul du budget disponible pour le tour en cours

	// Accesseurs
	const string getName() const; // Accesseur de name
	const int getCitiesLenght() const; // Accesseur de la longueur de cities
	vector<City*> getNeighbourhood(); // Liste des villes voisines de la faction
	float getBudget() const; // Accesseur du budget
	float getPrice() const; // Accesseur du prix
	int getPopulation() const; // Calculateur du total de population
	float getTempBudget() const; // Accesseur du budget de tour

	// Setters
	void setBudget(float arg_budget); // setter de budget
	void budgetGrowing(City* setBy); // Croissance du budget
	void setTemporaryBudget(float arg_temp); // setter du budget sur le tour

	// Victoire
	void getVictory(); // Victoire

private:
	static int factionNumber;
	string name;
	int id;
	float budget; // argent disponible
	float temporaryBudget; // argent disponible sur le tour
	float price;
	vector<City*> cities;
	mutex inSetting; // Mutex pour la croissance du budget en fin de tour
};

