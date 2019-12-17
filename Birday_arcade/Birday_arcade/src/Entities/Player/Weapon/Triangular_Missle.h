#include "P_Weapon.h"

#pragma once
class Triangular_Missle:public P_Weapon
{
public:
	Triangular_Missle(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Triangular_Missle();

	int damage();

	void abilities(bool collide);

private:
	int type;

	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;
};

