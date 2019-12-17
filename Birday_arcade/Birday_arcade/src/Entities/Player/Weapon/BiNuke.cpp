#include "BiNuke.h"

BiNuke::BiNuke(Image & sprite_sheet, int x, int y, int vel, int direction) :P_Weapon(sprite_sheet, x, y, vel, direction)
{
	set_bitmap(sprite_sheet.Player_Weapon_image(BI_NUKE).first, sprite_sheet.Player_image().second);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);

	cropping = al_create_bitmap(80, 80);
	cropping2 = al_create_bitmap(40, 40);

	this->hit_count = 0;
	this->type = 0;

}

BiNuke::~BiNuke()
{
}

int BiNuke::damage()
{
	return 9;
}

void BiNuke::abilities(bool collide)
{

	if (collide && hit_count == 2)
	{
		set_kill(true);
	}

	else
	{
		hit_count++;
		change_direction();
	}
}
