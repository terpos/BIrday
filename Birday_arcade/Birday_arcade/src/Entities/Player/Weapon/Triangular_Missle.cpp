#include "Triangular_Missle.h"



Triangular_Missle::Triangular_Missle(Image &sprite_sheet, int x, int y, int vel, int direction, int num_of_bounce): P_Weapon (sprite_sheet, x, y, vel, direction, num_of_bounce)
{
	set_id(TRIANGULAR_MISSILE);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);
	set_hit(false, num_of_bounce);


	type = 1;
}


Triangular_Missle::~Triangular_Missle()
{
}

int Triangular_Missle::damage()
{
	return 8;
}

