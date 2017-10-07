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
	int id;
	int population;
	float alimentation;
	float energie;
	float budget;
	//Tree<UNKNOWN> competences;
	//Tree<UNKNOWN> constructions;

};
