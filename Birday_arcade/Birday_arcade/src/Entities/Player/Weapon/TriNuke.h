#include "P_Weapon.h"

#pragma once
class TriNuke: public P_Weapon
{
public:
	TriNuke(Image &sprite_sheet, int x, int y, int vel, int direction, int num_of_bounce);
	~TriNuke();

	int damage();
	
	void render(Image expl, Sound sound, bool play_sound);


private:
	int type;

};

