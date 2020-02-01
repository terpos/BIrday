#include "P_Weapon.h"

#pragma once
class Arrow:public P_Weapon
{
public:
	Arrow(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Arrow();

	int damage();

private:
	int type;
	
	std::default_random_engine movement;

	
};

