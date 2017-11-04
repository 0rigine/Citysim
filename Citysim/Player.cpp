#include "stdafx.h"
#include "Player.h"
#include <iostream>
using namespace std;

Player::Player():City::City()
{
}


Player::~Player()
{
}

void Player::turn()
{
	cout << "Bonjour, vous etes le joueur 1 semble-t-il\n" << endl;
}
