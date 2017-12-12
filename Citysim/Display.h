#pragma once
#include <windows.h>
#include <iostream>
#include <conio.h>

//struct SMALL_RECT {
//	SHORT Left;
//	SHORT Top;
//	SHORT Right;
//	SHORT Bottom;
//};

// FONCTIONS CONSOLE
void color(int t, int f); // Fonction de changement de couleur
void adjustWindowSize(); // Reajustement de la fenêtre
void Locate(SHORT x, SHORT y); // placement du curseur

// FONCTIONS UTILISATEUR
void Firstscreen(); // accueil
void erase(int x, int y, int x_bis, int y_bis); // supprime affichage dans les coordonnees envoyees
