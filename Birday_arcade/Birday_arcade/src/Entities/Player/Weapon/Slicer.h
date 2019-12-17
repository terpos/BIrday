#include "P_Weapon.h"

#pragma once
class Slicer: public P_Weapon
{
public:
	Slicer(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Slicer();

	int damage();

	void abilities(bool collide);

private:
	int type;

	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;
};

