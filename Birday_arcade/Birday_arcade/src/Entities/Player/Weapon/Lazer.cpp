#include "Lazer.h"



Lazer::Lazer(Image &sprite_sheet, int x, int y, int vel, int direction, int num_of_bounce) : P_Weapon(sprite_sheet, x, y, vel, direction, num_of_bounce)
{
	set_id(LAZER);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);
	set_hit(false, num_of_bounce);

	set_kill(false);

	type = 0;
}


Lazer::~Lazer()
{
}

int Lazer::damage()
{
	return 1;
}


