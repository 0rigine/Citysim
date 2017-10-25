#include "stdafx.h"
#include "Grille.h"
using namespace std;

int main()
{
	vector< vector<City>> test = Grille::initialize_Grid(1, 1);
	test[0].push_back(City("Ville2"));
	test[0][0].acheterVille(test[0][1]);
	system("pause");

    return 0;
}
