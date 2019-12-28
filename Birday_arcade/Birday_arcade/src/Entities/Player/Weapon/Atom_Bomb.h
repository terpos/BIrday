#include "P_Weapon.h"

#pragma once
class Atom_Bomb:public P_Weapon
{
public:
	Atom_Bomb(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Atom_Bomb();

	void abilities();

	void render(Image expl);

private:
	int type;

	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;

};

