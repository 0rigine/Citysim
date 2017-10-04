#pragma once
#include <iostream>
#include <string>
#include "Tree.h"
using namespace std;

class City
{
public:
	City();
	~City();

protected:
	// Attributes
	string nom;
	string faction;
	int population;
	int alimentation;
	int energie;
	int budget;
	//Tree<UNKNOWN> competences;
	//Tree<UNKNOWN> constructions;
};
