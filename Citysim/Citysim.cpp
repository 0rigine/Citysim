#include "stdafx.h"
#include <random>
#include <time.h>
#include <iostream>
using namespace std;
#include "Grille.h"

int main()
{
	srand(time(NULL));
	Grille test = Grille(2,2);
	test.playATurn();
	system("pause & cls");
	test.afficherVilles();

	system("pause");
    return 0;
}
