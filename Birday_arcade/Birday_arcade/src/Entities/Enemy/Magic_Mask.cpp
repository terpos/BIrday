#include "Magic_Mask.h"



Magic_Mask::Magic_Mask(Image &sprite_sheet, int version, int x, int y, int vel, int direction): Enemy(sprite_sheet, version, x, y, vel, direction)
{
	if (version == 1)
	{
		set_bitmap(sprite_sheet.Enemy_image(MAGIC_MASK).first, sprite_sheet.Player_image().second);
		set_health(2);
	}

	else
	{
		set_bitmap(sprite_sheet.Enemy_image(MAGIC_MASK2).first, sprite_sheet.Player_image().second);
		set_health(4);
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


Magic_Mask::~Magic_Mask()
{
}

int Magic_Mask::Damage()
{
	if (get_version() == 1)
	{
		return 2;
	}

	else
	{
		return 4;
	}
}

void Magic_Mask::shoot(std::vector<E_Weapon*>& eweapon, Options option, Sound sound, Image spritesheet)
{
	std::uniform_int_distribution<int > shoot(0, 21);

	if (reload_time > 0)
	{
		this->reload_time--;
	}

	else if (reload_time == 0)
	{
		if (shoot(shooting_probability) > 5 && shoot(shooting_probability) < 15)
		{
			if (option.get_sound_options())
			{
				al_set_sample_instance_position(sound.sound_effects(10), 0);
				al_play_sample_instance(sound.sound_effects(10));
			}
			eweapon.push_back(new Fire(spritesheet, get_x(), get_y(), 20, get_direction()));
			this->reload_time = 40;
		}

		else if (shoot(shooting_probability) > 15)
		{
			if (option.get_sound_options())
			{
				al_set_sample_instance_position(sound.sound_effects(22), 0);
				al_play_sample_instance(sound.sound_effects(22));
			}
			eweapon.push_back(new Thunder(spritesheet, get_x(), get_y(), 20, get_direction()));
			this->reload_time = 40;
		}

		else
		{
			reload_time = 40;
		}

	}
}
