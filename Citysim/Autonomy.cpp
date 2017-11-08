#include "stdafx.h"
#include "Autonomy.h"

Autonomy::Autonomy():City::City()
{
}


Autonomy::~Autonomy()
{
}

void Autonomy::turn()
{
	set_Farmers(50);
	set_Energize(50);

	growth(); // croissance de la ville en fin de tour
}
