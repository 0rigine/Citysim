#pragma once
#include "City.h"

/* Classe de ville dirigée par un joueur héritant de City */
class Player :
	public City
{
public:
	Player();
	virtual ~Player();

	// Interface
	virtual void turn(); // tour de jeu
	void setEmployes(string jobName, int (City::*setter)(int)); // fonction d'assignation des employés
	bool ask(string question); // fonction pour poser une question (insertion sécurisée)
	void buy(); // acheter une ville
};
