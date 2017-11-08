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

	// Fin de partie
	virtual void victory();
	virtual void defeat();
};
