#pragma once
#include "City.h"

/* Ville contr�l�e par intelligence artificielle h�ritant de City */
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
