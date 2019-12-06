#include "P_Weapon.h"

#pragma once
class Stunner: public P_Weapon
{
public:
	Stunner(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Stunner();

private:
	int type;

	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;
};

