#include "E_Weapon.h"

#pragma once
class Grapple:public E_Weapon
{
public:
	Grapple(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Grapple();

private:
	int x, y, vel, direction, buttons[7], type;

	bool draw;

	ALLEGRO_BITMAP *cropping;

};

