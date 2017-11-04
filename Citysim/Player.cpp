#include "stdafx.h"
#include "Player.h"
#include <iostream>
using namespace std;
#include "Faction.h"

Player::Player():City::City()
{
}


Player::~Player()
{
}

void Player::turn()
{
	presentation();
	working();
}
