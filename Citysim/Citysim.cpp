#include "stdafx.h"
#include <random>
#include <time.h>
using namespace std;
#include "Grille.h"

int main()
{
	srand(time(NULL));
	vector< vector<City*>> test = Grille::initialize_Grid(1, 1);
	//test[0].push_back(new City());
	//test[0][0]->acheterVille(test[0][1]);

	system("pause");
    return 0;
}
