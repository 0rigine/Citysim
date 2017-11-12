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
	cout << "Launching..." << endl;
	set_Farmers(50);
	cout << "Success !" << endl;
	set_Energize(40);
	set_Traders(10);
	cout << "Ending..." << endl;
}

void Autonomy::victory()
{
}

void Autonomy::defeat()
{
}
