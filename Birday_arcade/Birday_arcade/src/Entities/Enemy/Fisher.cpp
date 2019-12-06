#include "Fisher.h"



Fisher::Fisher(Image &sprite_sheet, int version, int x, int y, int vel, int direction) : Enemy(sprite_sheet, version, x, y, vel, direction)
{
	if (version == 1)
	{
		set_bitmap(sprite_sheet.Enemy_image(FISHER).first, sprite_sheet.Player_image().second);
	}

	else
	{
		set_bitmap(sprite_sheet.Enemy_image(FISHER).first, sprite_sheet.Player_image().second);
	}

	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);
	set_hit(false, NULL);
	set_health(10);

	seed = std::chrono::system_clock::now().time_since_epoch().count();
	movement.seed(seed);
	shooting_probability.seed(seed);

	nochange = 25;
	reload_time = 25;
	cropping = al_create_bitmap(80, 80);
}


Fisher::~Fisher()
{
}
