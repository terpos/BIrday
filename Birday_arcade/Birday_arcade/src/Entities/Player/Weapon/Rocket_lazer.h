#include "P_Weapon.h"

#pragma once
class Rocket_lazer: public P_Weapon
{
public:
	Rocket_lazer(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Rocket_lazer();

private:
	int type;

	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;
};

