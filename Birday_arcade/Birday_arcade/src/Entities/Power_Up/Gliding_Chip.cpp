#include "Gliding_Chip.h"



Gliding_Chip::Gliding_Chip(Image image, int x, int y): Power_Up(image, x, y)
{
	set_bitmap(image.Power_Up_image(GLIDING_CHIP).first, image.Power_Up_image(0).second);
	set_x(x);
	set_y(y);
}


Gliding_Chip::~Gliding_Chip()
{
}

void Gliding_Chip::power_up_abilities(Sound sound, Player* & player, std::vector<Enemy*>& enemy)
{

	al_play_sample_instance(sound.sound_effects(9));

	player->set_vel(10);
	player->set_glide(true);
	player->set_delay_movemement(200);


}
