#include "P_Weapon.h"

#pragma once
class Lazer: public P_Weapon
{
public:
	Lazer(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Lazer();

	int damage();

private:
	int type;

	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;
};

