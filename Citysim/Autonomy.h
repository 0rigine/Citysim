#pragma once
#include "City.h"

/* Ville contr�l�e par intelligence artificielle h�ritant de City */
class Autonomy :
	public City
{
public:
	Autonomy();
	virtual ~Autonomy();

	virtual void turn();
};
