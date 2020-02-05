#include "P_Weapon.h"

#pragma once
class Lazer: public P_Weapon
{
public:
	Lazer(Image &sprite_sheet, int x, int y, int vel, int direction, int num_of_bounce);
	~Lazer();

	int damage();

private:
	int type;

};

