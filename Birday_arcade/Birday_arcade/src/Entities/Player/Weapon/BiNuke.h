#include "P_Weapon.h"

#pragma once
class BiNuke :public P_Weapon
{
public:
	BiNuke(Image &sprite_sheet, int x, int y, int vel, int direction);
	~BiNuke();

	int damage();

	void render(Image expl);

private:
	int type;

	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;
};

