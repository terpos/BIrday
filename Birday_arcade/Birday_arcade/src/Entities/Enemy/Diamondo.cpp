#include "Diamondo.h"



Diamondo::Diamondo(Image &sprite_sheet, int version, int x, int y, int vel, int direction) : Enemy(sprite_sheet, version, x, y, vel, direction)
{
	if (version == 1)
	{
		set_bitmap(sprite_sheet.Enemy_image(DIAMONDO).first, sprite_sheet.Player_image().second);
		set_health(4);
	}

	else
	{
		set_bitmap(sprite_sheet.Enemy_image(DIAMONDO2).first, sprite_sheet.Player_image().second);
		set_health(8);
	}

	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);
	set_hit(false, NULL);

	seed = std::chrono::system_clock::now().time_since_epoch().count();
	movement.seed(seed);
	shooting_probability.seed(seed);

	nochange = 25;
	reload_time = 25;
	cropping = al_create_bitmap(80, 80);
}


Diamondo::~Diamondo()
{
}

int Diamondo::Damage()
{
	if (get_version() == 1)
	{
		return 4;
	}

	else
	{
		return 8;
	}
}

void Diamondo::shoot(std::vector<E_Weapon*>& eweapon, Image spritesheet)
{
	std::uniform_int_distribution<int > shoot(0, 11);

	if (reload_time > 0)
	{
		this->reload_time--;
	}

	else if (reload_time == 0)
	{
		if (shoot(shooting_probability) > 5)
		{
			eweapon.push_back(new Diamond_Ice(spritesheet, get_x(), get_y(), 20, get_direction()));
			this->reload_time = 20;
		}

		else if (shoot(shooting_probability) > 15)
		{
			eweapon.push_back(new Star_Bomb(spritesheet, get_x(), get_y(), 0, get_direction()));
			this->reload_time = 40;
		}

		else
		{
			reload_time = 40;
		}

	}
}
