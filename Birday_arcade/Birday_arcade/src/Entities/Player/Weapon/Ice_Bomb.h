#include "P_Weapon.h"

#pragma once
class Ice_Bomb:public P_Weapon
{
public:
	Ice_Bomb(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Ice_Bomb();

	void abilities();

	void render(Image expl, Sound sound);

private:
	int type;

	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;

	
};

