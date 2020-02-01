#include "Fire.h"



Fire::Fire(Image &sprite_sheet, int x, int y, int vel, int direction): E_Weapon(sprite_sheet, x, y, vel, direction)
{
	set_id(FIRE);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);

	cropping = al_create_bitmap(80, 80);
}


Fire::~Fire()
{
}

int Fire::damage()
{
	return 5;
}
