#include "E_Weapon.h"

#pragma once
class Star_Bomb:public E_Weapon
{
public:
	Star_Bomb(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Star_Bomb();

	int damage();

private:
	int x, y, vel, direction, buttons[7], type;

	bool draw;

	ALLEGRO_BITMAP *cropping;
	
};

