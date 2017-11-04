#include "stdafx.h"
#include <random>
#include <time.h>
#include <iostream>
using namespace std;
#include "Grille.h"
#include "Autonomy.h"
#include "Player.h"

int main()
{
	srand(time(NULL));
	vector< vector<City*> > test = Grille::initialize_Grid(2, 2);
	vector<vector<City*>>::iterator it;
	vector<City*>::iterator jt;
	for (it = test.begin(); it != test.end(); ++it)
	{
		for (jt = it->begin(); jt != it->end(); ++jt)
		{
			(*jt)->presentation();
		}
	}

	system("pause");
    return 0;
}
