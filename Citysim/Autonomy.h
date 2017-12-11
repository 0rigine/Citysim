#pragma once
#include "City.h"

/* Ville contrôlée par intelligence artificielle héritant de City */
class Autonomy :
	public City
{
public:
	Autonomy();
	virtual ~Autonomy();

	virtual void turn(); // tour de jeu

	// Contrats
	virtual void gererAccords(); // passage d'accords avec les villes voisines

	// Fin de partie
	virtual void victory();
	virtual void defeat();
};
