#pragma once
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

#define DEFAULT_COLOR 15
#define PLAYER_COLOR 12

class Console
{
public:
	// FONCTIONS CONSOLE
	static void color(int t, int f); // Fonction de changement de couleur
	static void locate(SHORT x, SHORT y); // placement du curseur
	static void adjustWindowSize(); // redimension en plein écran de la console
	static void showConsoleCursor(bool showBool = false); // afficher / masquer curseur console
	static void erase(int x, int y, int x_bis, int y_bis); // supprime affichage dans les coordonnees envoyees

	// FONCTIONS UTILISATEUR
	static void firstscreen(); // accueil
	static int choix(vector<string> ch, int x, int y); // Creation d'un menu
	static void choiceTown(int * choice_x, int * choice_y, int taille_x, int taille_y); // sélection ville


	// Variables Console
	static COORD dim;
	static HANDLE console;
};