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
	set_Energize(40);
	set_Traders(10);
}

void Autonomy::victory()
{
}
