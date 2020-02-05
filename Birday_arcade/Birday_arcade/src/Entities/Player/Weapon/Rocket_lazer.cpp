#include "Rocket_lazer.h"



Rocket_lazer::Rocket_lazer(Image &sprite_sheet, int x, int y, int vel, int direction, int num_of_bounce) : P_Weapon(sprite_sheet, x, y, vel, direction, num_of_bounce)
{
	set_id(ROCKET_LAZER);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);
	set_hit(false, num_of_bounce);

	type = 1;
}


Rocket_lazer::~Rocket_lazer()
{
}

int Rocket_lazer::damage()
{
	return 2;
}

