#include "E_Weapon.h"

#pragma once
class Gunk: public E_Weapon
{
public:
	Gunk(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Gunk();

private:
	int x, y, vel, direction, buttons[7], type;

	bool draw;

	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;

	std::pair <ALLEGRO_BITMAP*, int> image;
};

