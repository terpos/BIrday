#include "Health_Chip.h"



Health_Chip::Health_Chip(Image image, int x, int y): Power_Up(image, x, y)
{
	set_id(HEALTH_CHIP);
	set_x(x);
	set_y(y);
}


Health_Chip::~Health_Chip()
{
}

void Health_Chip::power_up_abilities(Sound sound, Player* & player, std::vector<Enemy*>& enemy, std::vector <B_2_Bomber*> &b2, std::vector <needle_wind*> &nw, Options option)
{
	if (option.get_sound_options())
	{
		al_play_sample_instance(sound.sound_effects(12));
	}

	player->set_health(player->get_health() + 25);
}
