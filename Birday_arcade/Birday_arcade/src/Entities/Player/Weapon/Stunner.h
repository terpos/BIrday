#include "P_Weapon.h"

#pragma once
class Stunner: public P_Weapon
{
public:
	Stunner(Image &sprite_sheet, int x, int y, int vel, int direction, int num_of_bounce);
	~Stunner();

	int damage();

	void abilities();

private:
	int type;

	
};

