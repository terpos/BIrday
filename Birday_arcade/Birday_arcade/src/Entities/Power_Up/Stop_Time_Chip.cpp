#include "Stop_Time_Chip.h"



Stop_Time_Chip::Stop_Time_Chip(Image image, int x, int y): Power_Up(image, x, y)
{
	set_id(STOP_CHIP);
	set_x(x);
	set_y(y);
}


Stop_Time_Chip::~Stop_Time_Chip()
{
}

void Stop_Time_Chip::power_up_abilities(Sound sound, Player* & player, std::vector<Enemy*>& enemy, Options option)
{
	if (option.get_sound_options())
	{
		al_play_sample_instance(sound.sound_effects(20));
	}

	for (int i = 0; i < enemy.size(); i++)
	{
		enemy[i]->set_vel(0);
	}
}
