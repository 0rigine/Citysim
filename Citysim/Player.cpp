#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Player.h"
#include "Faction.h"
#include "Display.h"

Player::Player():City::City()
{
}


Player::~Player()
{
}

void Player::turn()
{
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

int Player::Choix(const char * ch[], int taille, int x, int y)
{
	int i, curseur = 0;
	Locate(x, y);
	int y_bis = y;
	for (i = 0; i < taille; i++)
	{
		++y;
		printf("  %s\n", ch[i]);
		Locate(x, y);
	}

	while (1) // gauche 0x4B   droite 0x77 haut 0x50  bas 0x48
	{
		int touche = _getch();
		Locate(x, y_bis + curseur);
		printf(" ");
		if (touche == 0x50 && curseur < taille - 1)
			curseur++;
		if (touche == 0x48 && curseur > 0)
			curseur--;
		if (touche == 0x0D)
			return curseur + 1;
		Locate(x, y_bis + curseur);
		printf(">");
		Locate(189, 0);
	}
	return 0;
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
