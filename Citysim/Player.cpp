#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

#include "Player.h"
#include "Faction.h"
#include "Display.h"
#include "Grille.h"

Player::Player():City::City()
{
	setColor(PLAYER_COLOR);
}

Player::Player(string name, float food, float energy, float wallet) :
	City::City(name, 1,300, food, energy, wallet)
{
	setColor(PLAYER_COLOR);
}


Player::~Player()
{
}

void Player::turn()
{
	int choice(0);
	vector<string> menu(
		{
			"Inspecter",
			"Assigner les employes",
			"Acheter une ville",
			"Fin de tour"
		}
	);
	presentation();
	while (true)
	{
		choice = Console::choix(menu, 5, 25);
		switch (choice)
		{
		case 0 :
			inspection();
			break;
		case 1:
			presentation();
			while (generalSettingEmployees(setEmployes("de fermiers"), setEmployes("de traders"), setEmployes("d'ingenieurs")) == ATTRIBUTION_ERROR);
			presentation();
			break;
		case 2 :
			buy();
			break;
		case 3 :
			return;
		default:
			break;
		}
	}
}

int Player::setEmployes(string jobName)
{
	int assigned(0);
	do
	{
		Console::erase(0, 25, 100, 40);
		Console::locate(40, 25);
		cout << "Saisir le nombre " << jobName << " (-1 pour ignorer) : ";
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cin >> assigned;
	} while (cin.fail() || assigned < -1);
	Console::erase(0, 25, 100, 40);
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
	int i(0);
	int choice(0);
	int size(0);
	float price(0); // prix d'achat proposé
	vector<City*> voisines;
	vector<City*> toBuy;
	vector<string> names({});
	vector<int> prices({});
	Console::erase(0, 25, 100, 40);
	Console::locate(40,25);
	if (getFaction()->canBuy())
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
			names.push_back(town->getName());
			prices.push_back(town->getPrice());
		}

		size = toBuy.size();
		do
		{
			do
			{
				Console::erase(0, 25, 100, 40);
				Console::locate(40, 25);
				cout << "Saisir l'index de la ville a acheter : " << ends;
				Console::choix(names, 40, 27,prices);
			} while (choice < 0 || choice > size - 1);
			do
			{
				Console::locate(80, 25);
				cout << "Prix propose : " << ends;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> price;
			} while (cin.fail() || price < 1 || getWallet() < price);
		} while (!acheterVille(toBuy[choice], price));
		Console::erase(0, 25, 100, 40);
		Console::locate(40, 25);
		cout << "Proposition de rachat envoyee !" << endl;
	}
	else
	{
		cout << "Aucune ville ne peut etre achetee";
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

void Player::inspection()
{
	int curseur_x(0),
		curseur_y(0),
		touche(0),
		taille_x(getGame()->getDim_x()),
		taille_y(getGame()->getDim_y());
	City* temp(NULL);
	while (true)
	{
		touche = _getch();
		Console::locate(0 + curseur_y * 8, 3 + curseur_x * 4);
		cout << " ";
		if (touche == 0x4D && curseur_y < taille_y - 1) // haut 0x50
		{
			curseur_y++;
		}
		if (touche == 0x4B && curseur_y > 0) // bas 0x48
			curseur_y--;

		if (touche == 0x50 && curseur_x < taille_x - 1) // droite 0x4D
		{
			curseur_x++;
		}
		if (touche == 0x48 && curseur_x > 0) // gauche 0x4B
			curseur_x--;

		if (touche == 0x0D)
		{
			return;
		}
		Console::locate(0 + curseur_y * 8, 3 + curseur_x * 4);
		cout << ">";
		temp = getGame()->getCityAt(curseur_x, curseur_y);
		temp->presentation();
	}
}

void Player::saisirContrat()
{
	float food(0),
		cost(0),
		energy(0);
	int time(0);

	Console::erase(0, 25, 100, 40);
	Console::locate(40, 25);
	cout << "Saisir le contrat : ";
	Console::showConsoleCursor(true);
	Console::erase(0, 25, 100, 40);
	Console::locate(40, 25);
	cout << "Prix propose : ";
	cin >> cost;

	Console::erase(0, 25, 100, 40);
	Console::locate(40, 25);
	cout << "Nourriture echangee : ";
	cin >> food;

	Console::erase(0, 25, 100, 40);
	Console::locate(40, 25);
	cout << "Energie echangee : ";
	cin >> energy;

	Console::erase(0, 25, 100, 40);
	Console::locate(40, 25);
	cout << "Duree du contrat (en tours) : ";
	cin >> time;

	Console::showConsoleCursor(false);
	proposerContrat(time, cost, food, energy);
}

void Player::victory()
{
	Console::erase(0, 0, 100, 40);
	Console::locate((Console::dim.X + 14) / 2, 24);
	cout << "Le monde vous appartient !" << endl;
	Console::locate((Console::dim.X + 14) / 2, 26);
	cout << "Victoire !" << endl;
}

void Player::defeat()
{
	Console::erase(0, 0,100, 40);
	Console::locate((Console::dim.X + 14) / 2, 24);
	cout << "Budget et population insuffisants pour continuer !" << endl;
	Console::locate((Console::dim.X + 14) / 2, 25);
	cout << "Partie terminee" << endl;
	_getch();
	exit(EXIT_SUCCESS);
}

void Player::achatFinTour()
{
	if (getAcheteur() != NULL)
	{
		Console::erase(0, 0, 100, 40);
		Console::locate((Console::dim.X + 14) / 2, 24);
		cout << "Vous avez ete rachete !" << endl;
		Console::locate((Console::dim.X + 14) / 2, 25);
		cout << "Partie terminee" << endl;
		_getch();
		exit(EXIT_SUCCESS);
	}
}
