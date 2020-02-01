#include "Ball_shot.h"

Ball_shot::Ball_shot(Image &sprite_sheet, int x, int y, int vel, int direction): E_Weapon(sprite_sheet, x, y, vel, direction)
{
	set_id(BALL_SHOT);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);

	cropping = al_create_bitmap(80, 80);
}

Ball_shot::~Ball_shot()
{

}

int Ball_shot::damage()
{
	return 10;
}

