#include "stdafx.h"
#include "Player.h"
#include <iostream>
using namespace std;
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
		setEmployes("d'energiciens", &City::set_Energize);
	}
	working();

	growth(); // croissance de la ville en fin de tour
}

void Player::setEmployes(string jobName, int (City::*setter)(int))
{
	int assigned(0);
	do
	{
		cout << "Saisir le nombre " << jobName << " (-1 pour ignorer) : " << endl;
		cin >> assigned;
	} while (assigned < -1);
	if (assigned > -1)
	{
		(this->*setter)(assigned);
	}
	cout << endl;
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
