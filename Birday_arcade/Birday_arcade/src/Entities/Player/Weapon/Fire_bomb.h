#include "P_Weapon.h"

#pragma once
class Fire_bomb: public P_Weapon
{
public:
	Fire_bomb(Image &sprite_sheet, int x, int y, int vel, int direction, int num_of_bounce);
	~Fire_bomb();
	
	int damage();
	void abilities();

	void render(Image expl, Sound sound, bool play_sound);

private:
	int type;

};

