#include "stdafx.h"

#include <iostream>
#include <algorithm>
using namespace std;

#include "Faction.h"
#include "City.h"
#include "RandomName.h"
#include "Grille.h"
#include "Contrat.h"

int City::cityNumber = 0;


City::City() :
	bonheur(1),
	population(DEFAULT_POPULATION),
	nourriture(DEFAULT_FOOD),
	energie(DEFAULT_ENERGY),
	farmers(DEFAULT_FARMERS),
	energizer(DEFAULT_ENERGIZER),
	traders(DEFAULT_TRADERS),
	acheteur(NULL),
	prix(1),
	game(NULL),
	propositionsContrats(NULL)
{
	initiate();
	nom = RandomName::generate();
	faction = new Faction(nom, this);
	id = City::cityNumber;
}

City::City(int arg_posx, int arg_posy):
	bonheur(1),
	population(DEFAULT_POPULATION),
	nourriture(DEFAULT_FOOD),
	energie(DEFAULT_ENERGY),
	farmers(DEFAULT_FARMERS),
	energizer(DEFAULT_ENERGIZER),
	traders(DEFAULT_TRADERS),
	acheteur(NULL),
	prix(1),
	game(NULL),
	propositionsContrats(NULL)
{
	initiate(arg_posx, arg_posy);
}

City::City(string name, int arg_posx, int arg_posy, float arg_bonheur, int arg_population, float arg_nourriture, float arg_energie, float arg_budget):
	bonheur(1),
	population(DEFAULT_POPULATION),
	nourriture(DEFAULT_FOOD),
	energie(DEFAULT_ENERGY),
	farmers(DEFAULT_FARMERS),
	energizer(DEFAULT_ENERGIZER),
	traders(DEFAULT_TRADERS),
	acheteur(NULL),
	prix(1),
	game(NULL),
	propositionsContrats(NULL)
{
	initiate(arg_posx, arg_posy, name);
	population = arg_population;
	nourriture = arg_nourriture;
	energie = arg_energie;
	bonheur = arg_bonheur;
}

void City::initiate(int posx, int posy, string arg_name)
{
	id = City::cityNumber;
	++City::cityNumber;
	nom = arg_name;
	faction = new Faction(nom, this);
	coord_x = posx;
	coord_y = posy;
}


City::~City()
{
}

// Affichages
void City::presentation()
{
	cout << "[" << faction->getName() << "] " << nom << "\n" << endl;
	cout << "Prix : " << prix << endl;
	cout << "Population : " << population << endl;
	cout << "Nourriture : " << nourriture << endl;
	cout << "Energie : " << energie << endl;
	cout << "Budget : " << faction->getBudget() << endl;
	cout << endl;
}

void City::working()
{
	int totalEmployes(energizer + farmers + traders);
	cout << "Employes : " << totalEmployes << "/" << population << endl;
	cout << "Fermiers : " << farmers << endl;
	cout << "Traders : " << traders << endl;
	cout << "Ingenieurs : " << energizer << endl;
	cout << endl;
}

//Croissance
void City::growth()
{
	float coeffHappy = happinessPart();
	energyGrowth(coeffHappy);
	foodGrowth(coeffHappy);
	happinessGrowth(coeffHappy);
	populationGrowth(coeffHappy);
}

void City::energyGrowth(float coeffHappy)
{
	float coefficient(1); // coefficient bonus
	float quantity(50); // energie produite par habitant
	float consommation(10); // energie consommee par habitant
	// Production en fonction du bonheur de la population
	energie += (energizer*coefficient*quantity*coeffHappy)+(energizer*coefficient*(1- coeffHappy))-population*consommation;
	if (energie < 0) energie = 0;
}

void City::foodGrowth(float coeffHappy)
{
	float coefficient(1); // coefficient bonus
	float quantity(50); // nourriture produite par habitant
	float consommation(10); // nourriture consommee par habitant
	// Production en fonction du bonheur de la population
	nourriture += (farmers*coefficient*quantity*coeffHappy)+(farmers*coefficient*(1- coeffHappy))-population*consommation;
	if (nourriture < 0) nourriture = 0;
}

void City::populationGrowth(float coeffHappy)
{
	float coefficient(1); // coefficient bonus
	float coeffSad(1 / (2*bonheur)); // coefficient de population malheureuse disparaissant
	float coeffWorker(1);
	int newPopulation(0),travailleurs(0);
	int happy(coeffHappy*population); // habitants heureux
	int sad(population - happy); // population dont les besoins ne sont pas tous satisfaits
	newPopulation = population+(happy/2)-sad*coeffSad; // population restante

	travailleurs = farmers + energizer + traders; // total de travailleurs

	if (travailleurs > newPopulation) // ajustement des travailleurs à la population restante si inférieure
	{
		coeffWorker = (newPopulation / population);
		energizer *= coeffWorker;
		farmers *= coeffWorker;
		traders *= coeffWorker;
	}
	population = newPopulation;
}

void City::happinessGrowth(float coeffHappy)
{
	float coefficient(1); // coefficient bonus
	int happynessPop(coeffHappy*population); // population comblee
	int sadnessPop(population - happynessPop); // population en manque
	bonheur += happynessPop*coefficient - sadnessPop*coefficient/2; // calcul du bonheur selon la population heureuse et malheureuse
	if (bonheur <= 0) bonheur = 1;
}

float City::production()
{
	float coeffTraders(25.0), production(0);
	production = traders*coeffTraders;
	return production;
}

// Estimations et mesures
float City::happinessPart()
{
	float foodCons(10), energyCons(20); // besoins par habitant selon la ressource

	if (nourriture <= 0 || energie <= 0) return 0.0;

	float happyFood = (nourriture / foodCons) / population; // part de population dont les besoins en nourriture sont satisfaits
	if (happyFood > 1.0) happyFood = 1.0; // controle du pourcentage de population satisfaite en nourriture

	float happyEnergy = (energie / energyCons) / population; // part de population dont les besoins en energie sont satisfaits
	if (happyEnergy > 1.0) happyEnergy = 1.0; // controle du pourcentage de population satisfaite en énergie

	return happyFood*happyEnergy; // part de population dont tous les besoins sont satisfaits
}

float City::salary()
{
	float salaire(SALARY);
	return salaire*population;
}

float City::realSalary()
{
	float salaire(SALARY);
	int travailleurs(traders+farmers+energizer);
	return salaire*travailleurs;
}

// Achat/Vente de villes
bool City::acheterVille(City *achetee, float prix)
{
	lock_guard<mutex> lockBudget(faction->getInSetting());
	bool result(true);
	if (achetee->getFaction() != faction && prix < faction->getTempBudget())
	{
		achetee->propositionRachat(faction, prix); // proposition de rachat de la ville
	}
	else result = false;
	return result;
}

void City::propositionRachat(Faction * arg_acheteur, float proposition)
{
	lock_guard<mutex> noMultiNegociation(negocie); // on empêche d'autres négociations simultanées

	if (proposition > prix)
	{
		acheteur = arg_acheteur;
	}
}

void City::achatFinTour()
{
	if (acheteur != NULL)
	{
		acheteur->acheterVille(this, prix);
		acheteur = NULL;
	}
}

void City::estimate()
{
	prix = faction->getPrice() + bonheur;
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

vector<City*> City::get_Neighbour() const
{
	vector< vector<City*> > *worldMap(game->getMap());
	int sizex = worldMap->size();
	int sizey = worldMap->begin()->size();
	vector<City*> voisines; // vector contenant les villes voisines : Nord, Ouest, Est, Sud
	City* temp(NULL);
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (i*i != j*j)
			{
				if ( (0 <= coord_x + i && coord_x + i < sizex) && (0 <= coord_y + j && coord_y + j < sizey) )
				{
					temp = worldMap[0][coord_x + i][coord_y + j];
					if (temp->getFaction() != faction) voisines.push_back(temp); // on ajoute la ville aux voisines
				}
			}
		}
	}
	return voisines;
}

float City::getFood() const
{
	return nourriture;
}

float City::getEnergy() const
{
	return energie;
}

float City::getWallet() const
{
	return faction->getBudget();
}

float City::getPrice() const
{
	return prix;
}

Faction * City::getAcheteur() const
{
	return acheteur;
}

int City::getPopulation() const
{
	return population;
}

void City::set_Coord(int posx, int posy)
{
	coord_x = posx;
	coord_y = posy;
}

void City::set_Faction(Faction * newFaction)
{
	faction = newFaction;
}

void City::set_Game(Grille * grid)
{
	game = grid;
}


int City::generalSettingEmployees(int arg_farmers, int arg_traders, int arg_energizer)
{
	if (arg_farmers == -1) arg_farmers = farmers;
	if (arg_energizer == -1) arg_energizer = energizer;
	if (arg_traders == -1) arg_traders = traders;
	set_Farmers(0);
	set_Energize(0);
	set_Traders(0);
	return set_Farmers(arg_farmers) || set_Energize(arg_energizer) || set_Traders(arg_traders);
}

// Setters
int City::setEmployees(int toSet, int &employee, int tree)
{
	lock_guard<mutex> lockBudget(faction->getInSetting());
	int freePopulation(population + employee - farmers -energizer-traders),
		maximum(MAXIMUM_SETTLERS),
		result(ATTRIBUTION_OK),
		old(employee);
	employee = toSet;
	if (faction->getTempBudget() < salary() || toSet < 0 || toSet > maximum || toSet > freePopulation)
	{
		employee = old;
		result = ATTRIBUTION_ERROR;
	}
	return result;
}

int City::set_Farmers(int toSet)
{
	return setEmployees(toSet, farmers , 0);
}

int City::set_Energize(int toSet)
{
	return setEmployees(toSet, energizer, 0);
}

int City::set_Traders(int toSet)
{
	return setEmployees(toSet, traders, 0);
}

void City::proposerContrat(int duration, float arg_cost, float arg_nourriture, float arg_energie)
{
	Contrat *temp(NULL);
	temp = new Contrat(duration, arg_cost, this, NULL, arg_nourriture, arg_energie);
	if (propositionsContrats == NULL) propositionsContrats = new pileContrats(temp);
	else propositionsContrats->addNext(temp);
}

void City::resolveContract(float arg_food, float arg_energia, float arg_cost)
{
	nourriture += arg_food;
	energie += arg_energia;
	faction->resolveContract(arg_cost);
}

bool City::signerContrat(City * with, float marchandises[][3][3])
{
	return with->accorderContrat(this, marchandises); //WIP
}

bool City::accorderContrat(City * with, float marchandises[][3][3])
{
	lock_guard<mutex> NegoOpen(contractActions); // verrouillage des signatures de contrats
	Contrat* temp(NULL);
	if (propositionsContrats == NULL) return false; // pas de contrats à proposer
	temp = propositionsContrats->findContract(marchandises);
	if (temp != NULL)
	{
		propositionsContrats->removeThis(&propositionsContrats, marchandises);
	}
	else return false;
	temp->set_client(with);
	game->addContract(temp); // ajout du contrat à la liste des contrats de la grille
	return true;
}

void City::contratsVoisine(City * voisine)
{
}
