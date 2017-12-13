#pragma once
#include <Windows.h>

#define DEFAULT_COLOR 15

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
	static int choix(const char* ch[], int taille, int x, int y); // Creation d'un menu
	static COORD dim;
	static HANDLE console;
};