#include "E_Weapon.h"

#pragma once
class Diamond_Ice: public E_Weapon
{
public:
	Diamond_Ice(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Diamond_Ice();

	int damage();

private:
	int x, y, vel, direction, buttons[7], type;

	bool draw;
	
	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;

	std::pair <ALLEGRO_BITMAP*, int> image;

};

