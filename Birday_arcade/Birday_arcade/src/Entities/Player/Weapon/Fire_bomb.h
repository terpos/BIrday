#include "P_Weapon.h"

#pragma once
class Fire_bomb: public P_Weapon
{
public:
	Fire_bomb(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Fire_bomb();

	void abilities();

	void render(Image expl);

private:
	int type;

	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;

};

