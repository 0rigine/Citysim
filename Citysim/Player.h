#pragma once
#include "City.h"

/* Classe de ville dirigée par un joueur héritant de City */
class Player :
	public City
{
public:
	Player();
	Player(string name, float food, float energy, float wallet);
	virtual ~Player();
	virtual void turn(); // tour de jeu

	// Interface
	int setEmployes(string jobName); // fonction d'assignation des employés
	bool ask(string question); // fonction pour poser une question (insertion sécurisée)
	void buy(); // acheter une ville
	virtual void gererAccords(); // interface de passage d'accords
	void racheter_ville(); // rachat de ville
	void inspection(); // inspecter une ville
	void choiceTown(int * choice_x, int * choice_y, int taille_x, int taille_y);

	// Fin de partie
	virtual void victory(); // victoire
	virtual void defeat(); // défaite
	virtual void achatFinTour(); // défaite
};
