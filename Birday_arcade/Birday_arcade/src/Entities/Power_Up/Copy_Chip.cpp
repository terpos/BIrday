#include "Copy_Chip.h"



Copy_Chip::Copy_Chip(Image image, int x, int y): Power_Up(image, x, y)
{
	set_id(COPY_CHIP);
	set_x(x);
	set_y(y);

	seed = std::chrono::system_clock::now().time_since_epoch().count();
	power_up.seed(seed);
}


Copy_Chip::~Copy_Chip()
{
}

void Copy_Chip::power_up_abilities(Sound sound, Player *& player, std::vector<Enemy*>& enemy, std::vector <B_2_Bomber*> &b2, Options option)
{
	std::uniform_int_distribution <int> kind_of_powerup(0, 4);


	switch (kind_of_powerup(power_up))
	{

	case GLIDING_CHIP:
		if (option.get_sound_options())
		{
			al_play_sample_instance(sound.sound_effects(9));
		}

		player->set_vel(10);
		player->set_glide(true);
		player->set_delay_movemement(200);
		break;

	case HEALTH_CHIP:
		if (option.get_sound_options())
		{
			al_play_sample_instance(sound.sound_effects(12));
		}

		player->set_health(player->get_health() + 25);
		break;

	case NEEDLE_WIND_BLAST_CHIP:
		if (option.get_sound_options())
		{
			al_play_sample_instance(sound.sound_effects(21));
		}

		for (int i = 0; i < enemy.size(); i++)
		{
			if (enemy[i]->get_x() < player->get_x())
			{
				enemy.erase(enemy.begin() + i);
			}
		}
		break;

	case STOP_CHIP:
		if (option.get_sound_options())
		{
			al_play_sample_instance(sound.sound_effects(20));
		}

		for (int i = 0; i < enemy.size(); i++)
		{
			enemy[i]->set_vel(0);
		}
		break;

	case B_2_BOMBER_STRIKE_CHIP:
		if (option.get_sound_options())
		{
			al_play_sample_instance(sound.sound_effects(2));
		}

		b2.push_back(new B_2_Bomber(get_image()));

		break;
	
	}
}

int Copy_Chip::get_random_powerup()
{
	return this->random;
}
