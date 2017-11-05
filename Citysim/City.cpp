#include "stdafx.h"

#include "Faction.h"
#include "City.h"
#include "RandomName.h"
#include <iostream>
using namespace std;

int City::cityNumber = 0;


City::City():
	bonheur(1),
	population(100),
	nourriture(2000),
	energie(10000),
	budget(200000),
	farmers(0),
	energizer(0),
	traders(0)
{
	nom = RandomName::generate();
	faction = new Faction(nom, this);
	id = City::cityNumber;
	++City::cityNumber;


}

City::City(string name, float arg_bonheur, int arg_population, float arg_nourriture, float arg_energie, float arg_budget):
	bonheur(1),
	population(100),
	nourriture(2000),
	energie(10000),
	budget(200000),
	farmers(0),
	energizer(0),
	traders(0)
{
	id = City::cityNumber;
	++City::cityNumber;
	nom = name;
	faction = new Faction(nom, this);
	population = arg_population;
	nourriture = arg_nourriture;
	energie = arg_energie;
	budget = arg_budget;
	bonheur = arg_bonheur;
}


City::~City()
{
}

// Affichages
void City::presentation()
{
	cout << "[" << faction->getName() << "] " << nom << "\n" << endl;
	cout << "Population : " << population << endl;
	cout << "Nourriture : " << nourriture << endl;
	cout << "Energie : " << energie << endl;
	cout << "Budget : " << budget << endl;
	cout << endl;
}

void City::working()
{
	int totalEmployes(energizer + farmers + traders);
	cout << "Employes : " << totalEmployes << "/" << population << endl;
	cout << "Fermiers : " << farmers << endl;
	cout << "Traders : " << traders << endl;
	cout << "Energiciens : " << energizer << endl;
	cout << endl;
}

//Croissance
void City::growth()
{
	energyGrowth();
	foodGrowth();
	happinessGrowth();
	budgetGrowth();
	populationGrowth();
}

void City::energyGrowth()
{
	float coefficient(1); // coefficient bonus
	float quantity(50); // energie produite par habitant
	float consommation(20); // energie consommee par habitant
	float happyCoeff(happinessPart()); // part de population heureuse
	// Production en fonction du bonheur de la population
	energie += (energizer*coefficient*quantity*happyCoeff)+(energizer*coefficient*(1-happyCoeff))-population*consommation;
}

void City::foodGrowth()
{
	float coefficient(1); // coefficient bonus
	float quantity(30); // nourriture produite par habitant
	float consommation(10); // nourriture consommee par habitant
	float happyCoeff(happinessPart()); // part de population heureuse
	// Production en fonction du bonheur de la population
	nourriture += (farmers*coefficient*quantity*happyCoeff)+(farmers*coefficient*(1-happyCoeff))-population*consommation;
}

void City::populationGrowth()
{
	float coefficient(1); // coefficient bonus
	float coeffSad(1 / bonheur); // coefficient de population malheureuse disparaissant
	float coeffWorker(1);
	int newPopulation(0),travailleurs(0);
	int happy(happinessPart()*population); // habitants heureux
	int sad(population - happy); // population dont les besoins ne sont pas tous satisfaits
	newPopulation = population+(happy/2)-sad*coeffSad; // population restante

	travailleurs = farmers + energizer + traders; // total de travailleurs

	if (travailleurs > newPopulation) // ajustement des travailleurs à la population restante si inférieure
	{
		coeffWorker = (travailleurs - newPopulation) / newPopulation;
		energizer *= coeffWorker;
		farmers *= coeffWorker;
		traders *= coeffWorker;
	}
	population = newPopulation;
}

void City::happinessGrowth()
{
	float coefficient(1); // coefficient bonus
	int happynessPop(happinessPart()*population); // population comblee
	int sadnessPop(population - happynessPop); // population en manque
	bonheur += (happynessPop - sadnessPop)*coefficient; // calcul du bonheur selon la population heureuse et malheureuse
	if (bonheur <= 0) bonheur = 1;
}

void City::budgetGrowth()
{
	float salaire(2.5),coeffTraders(25.0);
	int travailleurs = farmers + energizer + traders;
	budget += traders*coeffTraders - salaire*travailleurs;
}

// Estimations et mesures
float City::happinessPart()
{
	float foodCons(10), energyCons(20); // besoins par habitant selon la ressource

	float happyFood = (nourriture / foodCons) / population; // part de population dont les besoins en nourriture sont satisfaits
	if (happyFood > 1.0) happyFood = 1.0; // controle du pourcentage de population satisfaite en nourriture

	float happyEnergy = (energie / energyCons) / population; // part de population dont les besoins en energie sont satisfaits
	if (happyEnergy > 1.0) happyEnergy = 1.0; // controle du pourcentage de population satisfaite en énergie
	float hapinnessTotal(happyFood*happyEnergy);

	return hapinnessTotal; // part de population dont tous les besoins sont satisfaits
}

// Achat/Vente de villes
void City::estAchetee(Faction *newFaction)
{
	faction = newFaction;
}

void City::acheterVille(City *achetee, float prix)
{
	faction->acheterVille(achetee, prix);
}

// Accesseurs
const string City::getName() const
{
	return nom;
}

Faction* City::getFaction() const
{
	return faction;
}


// Setters
int City::set_Farmers(int toSet)
{
	int freePopulation(population-energizer-traders);
	int maximum(100);
	if(toSet < 0 || toSet > maximum || toSet > freePopulation) return ATTRIBUTION_ERROR;
	farmers = toSet;
	return ATTRIBUTION_OK;
}

int City::set_Energize(int toSet)
{
	int freePopulation(population-farmers-traders);
	int maximum(100);
	if(toSet < 0 || toSet > maximum || toSet > freePopulation) return ATTRIBUTION_ERROR;
	energizer = toSet;
	return ATTRIBUTION_OK;
}

int City::set_Traders(int toSet)
{
	int freePopulation(population-farmers-energizer);
	int maximum(100);
	if(toSet < 0 || toSet > maximum || toSet > freePopulation) return ATTRIBUTION_ERROR;
	traders = toSet;
	return ATTRIBUTION_OK;
}