#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Player.h"
#include "Faction.h"

Player::Player():City::City()
{
}


Player::~Player()
{
}

void Player::turn()
{
	presentation();
	working();
	
	if (ask("Changer les employes (o/n) ?"))
	{
		setEmployes("de fermiers", &City::set_Farmers);
		setEmployes("de traders", &City::set_Traders);
		setEmployes("d'ingenieurs", &City::set_Energize);
	}
	working();

	growth(); // croissance de la ville en fin de tour
}

void Player::setEmployes(string jobName, int (City::*setter)(int))
{
	int assigned(0);
	int attribution(ATTRIBUTION_OK);
	do
	{
		do
		{
			cout << "Saisir le nombre " << jobName << " (-1 pour ignorer) : " << endl;
			cin >> assigned;
		} while (assigned < -1);
		if (assigned > -1)
		{
			attribution = (this->*setter)(assigned);
		}
		cout << endl;
	} while (attribution == ATTRIBUTION_ERROR);
}

bool Player::ask(string question)
{
	char choice;
	do
	{
		cout << question << endl;
		cin >> choice;
	} while (choice != 'o' && choice != 'n' && choice != 'O' && choice != 'N');
	return (choice == 'o' || choice == 'O');
}

void Player::buy()
{
	vector<City*> voisines;
	if (ask("Acheter une ville (o/n) ?"))
	{
		voisines = getFaction()->getNeighbourhood();
		for each (City* town in voisines)
		{
			if (town != NULL)
			{
				town->presentation();
				cout << endl;
			}
		}
	}
}
