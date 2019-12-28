#include "Cannon_Slug.h"



Cannon_Slug::Cannon_Slug(Image &sprite_sheet, int version, int x, int y, int vel, int direction): Enemy(sprite_sheet, version, x, y, vel, direction)
{
	if (version == 1)
	{
		set_bitmap(sprite_sheet.Enemy_image(CANNON_SLUG).first, sprite_sheet.Player_image().second);
		set_health(5);
	}

	else
	{
		set_bitmap(sprite_sheet.Enemy_image(CANNON_SLUG2).first, sprite_sheet.Player_image().second);
		set_health(10);
	}

	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);
	set_hit(false, NULL);

	seed = std::chrono::system_clock::now().time_since_epoch().count();
	movement.seed(seed);
	shooting_probability.seed(seed);
	initial_vel = get_vel();

	nochange = 25;
	reload_time = 40;
	cropping = al_create_bitmap(80, 80);
}


Cannon_Slug::~Cannon_Slug()
{
}

int Cannon_Slug::Damage()
{
	if (get_version() == 1)
	{
		return 6;
	}

	else
	{
		return 12;
	}
	
}

void Cannon_Slug::react(Image & image, Player* & player, std::vector<E_Weapon*>& eweapon)
{
	if (get_vel() > 0)
	{
		if (player->get_y() >= get_y() && player->get_y() + 80 <= get_y() + 80)
		{

			if (player->get_x() > get_x() && get_direction() == 0)
			{
				set_vel(15);

			}

			else if (player->get_x() < get_x() && get_direction() == 1)
			{
				set_vel(15);
			}

		}

		else if (player->get_x() >= get_x() && player->get_x() + 80 <= get_x() + 80)
		{

			if (player->get_y() > get_y() && get_direction() == 2)
			{
				set_vel(15);
			}

			else if (player->get_y() < get_y() && get_direction() == 3)
			{
				set_vel(15);
			}
		}

		else
		{
			set_vel(initial_vel);
		}
	}

}

void Cannon_Slug::shoot(std::vector<E_Weapon*>& eweapon, Image spritesheet)
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
			eweapon.push_back(new Missile(spritesheet, get_x(), get_y(), 20, get_direction()));
			this->reload_time = 40;
		}

		else
		{
			this->reload_time = 40;
		}

	}
}
