#include "Ball.h"



Ball::Ball(Image &sprite_sheet, int version, int x, int y, int vel, int direction): Enemy(sprite_sheet, version, x, y, vel, direction)
{
	if (version == 1) 
	{
		set_bitmap(sprite_sheet.Enemy_image(BALL).first, sprite_sheet.Player_image().second);
		set_health(8);
	}

	else
	{
		set_bitmap(sprite_sheet.Enemy_image(BALL2).first, sprite_sheet.Player_image().second);
		set_health(16);
	}

	set_version(version);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);
	set_hit(false, NULL);

	seed = std::chrono::system_clock::now().time_since_epoch().count();
	movement.seed(seed);
	shooting_probability.seed(seed);

	nochange = 25;
	reload_time = 40;
	cropping = al_create_bitmap(80, 80);
}


Ball::~Ball()
{
}

int Ball::Damage()
{
	if (get_version() == 1)
	{
		return 12;
	}

	else
	{
		return 36;
	}
}

int Ball::get_score()
{
	if (get_version() == 1)
	{
		return 1000;
	}
	
	else
	{
		return 2000;
	}
}
