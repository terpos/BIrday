#include "P_Weapon.h"

#pragma once
class BiNuke :public P_Weapon
{
public:
	BiNuke(Image &sprite_sheet, int x, int y, int vel, int direction, int num_of_bounce);
	~BiNuke();

	int damage();

	void render(Image expl, Sound sound, bool play_sound);

private:
	int type;


};

