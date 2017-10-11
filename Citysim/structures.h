#pragma once

typedef struct contrat contrat;
struct contrat
{
	int timeLeft;
	float &resourceUsed;
	float cost;
	float quantity;
};
