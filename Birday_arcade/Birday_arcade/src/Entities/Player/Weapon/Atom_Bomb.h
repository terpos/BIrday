#include "P_Weapon.h"

#pragma once
class Atom_Bomb:public P_Weapon
{
public:
	Atom_Bomb(Image &sprite_sheet, int x, int y, int vel, int direction, int num_of_bounce);
	~Atom_Bomb();

	void abilities();

	void render(Image expl, Sound sound, bool play_sound);

private:
	int type;

};

