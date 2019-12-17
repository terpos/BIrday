#include "P_Weapon.h"

#pragma once
class TriNuke: public P_Weapon
{
public:
	TriNuke(Image &sprite_sheet, int x, int y, int vel, int direction);
	~TriNuke();

	int damage();

	void abilities(bool collide);



private:
	int type, hit_count;

	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;
};

