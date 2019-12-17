#include "E_Weapon.h"

#pragma once
class Bubble_Blast: public E_Weapon
{
public:
	Bubble_Blast(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Bubble_Blast();

	int damage();
private:
	int x, y, vel, direction, buttons[7], type;

	bool draw;

	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;

	std::pair <ALLEGRO_BITMAP*, int> image;
};

