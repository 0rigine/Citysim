#include "stdafx.h"
#include "Autonomy.h"
#include <iostream>
using namespace std;

Autonomy::Autonomy():City::City()
{
}


Autonomy::~Autonomy()
{
}

void Autonomy::turn()
{
	cout << "Ceci est une ville IA\n" << endl;
}
