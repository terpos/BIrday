#include "P_Weapon.h"

#pragma once
class Triangular_Missle:public P_Weapon
{
public:
	Triangular_Missle(Image &sprite_sheet, int x, int y, int vel, int direction);
	~Triangular_Missle();

	int damage();

private:
	int type;


};

