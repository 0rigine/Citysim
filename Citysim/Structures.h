#pragma once
#include "City.h"

typedef struct contrat contrat;
struct contrat
{
	City associate;
	int timeLeft;
	float &resourceUsed;
	float cost;
	float quantity;
};