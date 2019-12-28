#include "P_Weapon.h"

#pragma once
class Bomb: public P_Weapon
{
public:
	Bomb(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Bomb();

	void abilities();

	void render(Image expl);
private:
	
	int type;

	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;

};

