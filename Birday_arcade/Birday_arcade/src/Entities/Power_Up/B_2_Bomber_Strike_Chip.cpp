#include "B_2_Bomber_Strike_Chip.h"



B_2_Bomber_Strike_Chip::B_2_Bomber_Strike_Chip(Image image, int x, int y): Power_Up (image, x, y)
{
	set_bitmap(image.Power_Up_image(B_2_BOMBER_STRIKE_CHIP).first, image.Power_Up_image(0).second);
	set_x(x);
	set_y(y);
}


B_2_Bomber_Strike_Chip::~B_2_Bomber_Strike_Chip()
{
}

void B_2_Bomber_Strike_Chip::power_up_abilities(Sound sound, Player* & player, std::vector<Enemy*>& enemy, Options option)
{
	if (option.get_sound_options())
	{
		al_play_sample_instance(sound.sound_effects(2));
	}

	enemy.clear();
}
