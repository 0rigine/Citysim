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
	set_Farmers(60);
	set_Energize(40);

	growth(); // croissance de la ville en fin de tour
}
