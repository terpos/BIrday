#include "P_Weapon.h"

#pragma once
class Bomb: public P_Weapon
{
public:
	Bomb(Image &sprite_sheet, int x, int y, int vel, int direction, int num_of_bounce);
	~Bomb();

	void abilities();
	int damage();

	void render(Image expl, Sound sound, bool play_sound);
private:
	
	int type;

	

};

