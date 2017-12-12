#pragma once
#include "City.h"

/* Classe de ville dirigée par un joueur héritant de City */
class Player :
	public City
{
public:
	Player();
	virtual ~Player();
	virtual void turn(); // tour de jeu

	// Interface
	int setEmployes(string jobName); // fonction d'assignation des employés
	bool ask(string question); // fonction pour poser une question (insertion sécurisée)
	void buy(); // acheter une ville
	virtual void gererAccords(); // interface de passage d'accords
	void racheter_ville(int x, int y); // rachat de ville
	void choice(int * x, int * y, int taille_x, int taille_y); // parcours de la grille
	int Choix(const char* ch[], int taille, int x, int y); // Creation d'un menu

	// Fin de partie
	virtual void victory(); // victoire
	virtual void defeat(); // défaite
	virtual void Player::achatFinTour(); // défaite
	
};
