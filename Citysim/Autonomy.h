#pragma once
#include "City.h"

/* Ville contrôlée par intelligence artificielle héritant de City */
class Autonomy :
	public City
{
public:
	Autonomy();
	virtual ~Autonomy();

	virtual void turn();
};
