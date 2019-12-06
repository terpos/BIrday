#include "P_Weapon.h"

#pragma once
class Arrow:public P_Weapon
{
public:
	Arrow(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Arrow();

private:
	int type;
	
	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;
};

