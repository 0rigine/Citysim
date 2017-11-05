#include "stdafx.h"
#include <random>
#include <time.h>
#include <iostream>
using namespace std;
#include "Grille.h"

int main()
{
	srand(time(NULL));
	Grille test = Grille(5, 5);
	test.afficherVilles();

	system("pause");
    return 0;
}
