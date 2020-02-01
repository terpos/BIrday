#include "Rocket_lazer.h"



Rocket_lazer::Rocket_lazer(Image &sprite_sheet, int x, int y, int vel, int direction) : P_Weapon(sprite_sheet, x, y, vel, direction)
{
	set_id(ROCKET_LAZER);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);


	type = 1;
}


Rocket_lazer::~Rocket_lazer()
{
}

int Rocket_lazer::damage()
{
	return 2;
}

