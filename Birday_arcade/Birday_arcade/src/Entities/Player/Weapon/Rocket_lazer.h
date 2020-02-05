#include "P_Weapon.h"

#pragma once
class Rocket_lazer: public P_Weapon
{
public:
	Rocket_lazer(Image &sprite_sheet, int x, int y, int vel, int direction, int num_of_bounce);
	~Rocket_lazer();

	int damage();


private:
	int type;

};

