#pragma once
#include <string>
#include <vector>
using namespace std;

#include "City.h"

class Faction
{
public:
	Faction();
	Faction(string arg_name, City* capitale);
	~Faction();

	// Tour
	void update();

	// Achats / Vente
	void acheterVille(City *vendue, float prix = 10); // fonction d'achat de la ville
	void vendreVille(City *vendue, float prix = 10); // fonction de vente d'une ville

	// Accesseurs
	const string getName() const; // Accesseur de name
	const int getCitiesLenght() const; // Accesseur de la longueur de cities
	vector<City*> getNeighbourhood(); // Liste des villes voisines de la faction

	// Victoire
	void getVictory(); // Victoire

private:
	static int factionNumber;
	string name;
	int id;
	float budget; // argent disponible
	vector<City*> cities;
};

