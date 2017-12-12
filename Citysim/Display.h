#pragma once
#include <windows.h>
#include <iostream>
#include <conio.h>

// FONCTIONS CONSOLE
void color(int t, int f); // Fonction de changement de couleur
void adjustWindowSize(); // Reajustement de la fenêtre
void Locate(SHORT x, SHORT y); // placement du curseur

// FONCTIONS UTILISATEUR
void Firstscreen(); // accueil
void erase(int x, int y, int x_bis, int y_bis); // supprime affichage dans les coordonnees envoyees
int choix(const char* ch[], int taille, int x, int y); // Creation d'un menu
void our_faction(); // affichage ville joueur