#include "stdafx.h"
#include <random>
#include <time.h>
#include <iostream>
using namespace std;
#include "Grille.h"

int main()
{
	srand(time(NULL));
	vector< vector<City*>> test = Grille::initialize_Grid(1, 1);
	test[0].push_back(new City());
	test[0][0]->presentation();
	test[0][1]->presentation();
	cout << test[0][0]->getName() << " achete " << test[0][1]->getName() << " !\n" << endl;
	test[0][0]->acheterVille(test[0][1]);
	test[0][1]->presentation();

	system("pause");
    return 0;
}
