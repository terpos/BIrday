#include "E_Weapon.h"

#pragma once
class Fire: public E_Weapon
{
public:
	Fire(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Fire();

	int damage();

private:
	int x, y, vel, direction, buttons[7], type;

	bool draw;

	ALLEGRO_BITMAP *cropping;

};

