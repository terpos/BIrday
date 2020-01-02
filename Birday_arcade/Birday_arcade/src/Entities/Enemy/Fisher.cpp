#include "Fisher.h"



Fisher::Fisher(Image &sprite_sheet, int version, int x, int y, int vel, int direction) : Enemy(sprite_sheet, version, x, y, vel, direction)
{
	if (version == 1)
	{
		set_bitmap(sprite_sheet.Enemy_image(FISHER).first, sprite_sheet.Player_image().second);
		set_health(1);
	}

	else
	{
		set_bitmap(sprite_sheet.Enemy_image(FISHER2).first, sprite_sheet.Player_image().second);
		set_health(3);
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
	reload_time = 40;
	cropping = al_create_bitmap(80, 80);
}


Fisher::~Fisher()
{
}

int Fisher::Damage()
{
	if (get_version() == 1)
	{
		return 1;
	}

	else
	{
		return 3;
	}
}

void Fisher::react(Image &image, Sound sound, Player* & player, std::vector<E_Weapon*>& eweapon, Options option)
{
	if ((player->get_x() < get_x() + 240 && player->get_x() + 240 > get_x() && player->get_y() < get_y() + 240 && player->get_y() + 240 > get_y()) && get_vel() > 0)
	{
		if (option.get_sound_options())
		{
			al_play_sample_instance(sound.sound_effects(19));
		}

		if (player->get_direction() == 2 && get_direction() == 1)
		{
			eweapon.push_back(new Venom_Spit(image, get_x(), get_y(), 20, get_direction()));
		}

		else if (player->get_direction() == 3 && get_direction() == 0)
		{
			eweapon.push_back(new Venom_Spit(image, get_x(), get_y(), 20, get_direction()));
		}

		else if (player->get_direction() == 1 && get_direction() == 2)
		{
			eweapon.push_back(new Venom_Spit(image, get_x(), get_y(), 20, get_direction()));
		}

		else if (player->get_direction() == 0 && get_direction() == 3)
		{
			eweapon.push_back(new Venom_Spit(image, get_x(), get_y(), 20, get_direction()));
		}

		if (eweapon.size() > 1)
		{
			eweapon.erase(eweapon.begin() + 1);
		}
	}
}

void Fisher::shoot(std::vector <E_Weapon*> &eweapon, Options option, Sound sound, Image spritesheet)
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
			if (option.get_sound_options())
			{
				al_set_sample_instance_position(sound.sound_effects(4), 0);
				al_play_sample_instance(sound.sound_effects(4));
			}
			eweapon.push_back(new Bubble_Blast(spritesheet, get_x(), get_y(), 20, get_direction()));
			this->reload_time = 20;
		}

		else
		{
			reload_time = 20;
		}

	}
}
