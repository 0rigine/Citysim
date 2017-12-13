#pragma once
#include <string>
#include <vector>
#include <mutex>
using namespace std;

#include "City.h"

#define BASIC_COLOR 15

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

	// Contrats
	void resolveContract(float cost);

	// Accesseurs
	const string getName() const; // Accesseur de name
	const int getCitiesLenght() const; // Accesseur de la longueur de cities
	vector<City*> getNeighbourhood(); // Liste des villes voisines de la faction
	float getBudget() const; // Accesseur du budget
	float getPrice() const; // Accesseur du prix
	int getPopulation() const; // Calculateur du total de population
	float getTempBudget() const; // Accesseur du budget de tour
	mutex& getInSetting(); // Accesseur du mutex InSetting

	// Setters
	void setBudget(float arg_budget); // setter de budget
	void budgetGrowing(); // Croissance du budget
	void removeFromTemporaryBudget(float arg_temp); // Différence avec le budget utilisé

	// Victoire
	void getVictory(); // Victoire

private:
	static int factionNumber;
	string name;
	int id;
	int colori[2];
	float budget; // argent disponible
	float temporaryBudget; // argent disponible sur le tour
	float price;
	vector<City*> cities;
	mutex inSetting; // Mutex pour la croissance du budget en fin de tour
};
