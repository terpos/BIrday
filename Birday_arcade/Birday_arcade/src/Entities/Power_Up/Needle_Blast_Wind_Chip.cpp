#include "Needle_Blast_Wind_Chip.h"



Needle_Blast_Wind_Chip::Needle_Blast_Wind_Chip(Image image, int x, int y): Power_Up(image, x, y)
{
	set_bitmap(image.Power_Up_image(NEEDLE_WIND_BLAST_CHIP).first, image.Power_Up_image(0).second);
	set_x(x);
	set_y(y);
}


Needle_Blast_Wind_Chip::~Needle_Blast_Wind_Chip()
{
}

void Needle_Blast_Wind_Chip::power_up_abilities(Sound sound, Player* &player, std::vector<Enemy*>& enemy, Options option)
{
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
}
