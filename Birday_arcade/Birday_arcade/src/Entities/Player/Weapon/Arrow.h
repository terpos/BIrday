#include "P_Weapon.h"

#pragma once
class Arrow:public P_Weapon
{
public:
	Arrow(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Arrow();

	int damage();

	void abilities(bool collide);

private:
	int type, kill_count;
	
	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;
};

