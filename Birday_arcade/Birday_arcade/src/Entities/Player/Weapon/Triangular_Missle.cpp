#include "Triangular_Missle.h"



Triangular_Missle::Triangular_Missle(Image &sprite_sheet, int x, int y, int vel, int direction): P_Weapon (sprite_sheet, x, y, vel, direction)
{
	set_id(TRIANGULAR_MISSILE);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);
	set_hit(false, 0);


	type = 1;
}


Triangular_Missle::~Triangular_Missle()
{
}

int Triangular_Missle::damage()
{
	return 8;
}

