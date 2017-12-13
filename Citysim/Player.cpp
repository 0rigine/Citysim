#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Player.h"
#include "Faction.h"
#include "Display.h"

Player::Player():City::City()
{
	setColor(PLAYER_COLOR);
}


Player::~Player()
{
}

void Player::turn()
{
	vector<string> menu(
		{
			"Inspecter",

		}
	);
	/*presentation();
	working();
	
	if (ask("Changer les employes (o/n) ?"))
	{
		while (generalSettingEmployees(setEmployes("de fermiers"), setEmployes("de traders"), setEmployes("d'ingenieurs")) == ATTRIBUTION_ERROR);
	}
	working();

	buy();*/
}

int Player::setEmployes(string jobName)
{
	int assigned(0);
	do
	{
		cout << "Saisir le nombre " << jobName << " (-1 pour ignorer) : " << endl;
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cin >> assigned;
	} while (cin.fail() || assigned < -1);
	cout << endl;
	return assigned;
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
	int i(0);
	int choice(0);
	int size(0);
	float price(0); // prix d'achat proposé
	vector<City*> toBuy;
	if (getFaction()->canBuy() && ask("Acheter une ville (o/n) ?"))
	{
		voisines = getFaction()->getNeighbourhood();
		for each (City* town in voisines)
		{
			if (getFaction()->canBuyIt(town))
			{
				toBuy.push_back(town);
			}
		}
		for each (City* town in toBuy)
		{
			cout << "Index : " << i << " -> " << ends;
			town->presentation();
			cout << endl;
			++i;
		}
		size = toBuy.size();
		do
		{
			do
			{
				cout << "Saisir l'index de la ville a acheter : " << ends;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> choice;
			} while (cin.fail() || choice < 0 || choice > size - 1);
			do
			{
				cout << "Prix propose : " << ends;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> price;
			} while (cin.fail() || price < 1 || getWallet() < price);
		} while (!acheterVille(toBuy[choice], price));
		cout << "Proposition de rachat envoyee !" << endl;
	}
}

void Player::gererAccords()
{
}

void Player::racheter_ville()
{
	/*locate(100, 26);
	const char* tab_reponse_oui_non[] = { "Oui !","Non, je prefere attendre..." };
	int d = choix(tab_reponse_oui_non, 2, 105, 28);
	switch (d)
	{
	case 1: our_faction(); break;

	default: break;
	}*/
}

void Player::victory()
{
	cout << "Le monde vous appartient !" << endl;
	cout << "Victoire !" << endl;
}

void Player::defeat()
{
	cout << "Budget et population insuffisants pour continuer !" << endl;
	cout << "Partie terminee" << endl;
}

void Player::achatFinTour()
{
	if (getAcheteur() != NULL)
	{
		cout << "Vous avez ete rachete !" << endl;
		cout << "Partie terminee" << endl;
		exit(EXIT_SUCCESS);
	}
}
