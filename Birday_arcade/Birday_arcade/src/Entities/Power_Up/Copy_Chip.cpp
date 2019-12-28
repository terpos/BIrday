#include "Copy_Chip.h"



Copy_Chip::Copy_Chip(Image image, int x, int y): Power_Up(image, x, y)
{
	set_bitmap(image.Power_Up_image(COPY_CHIP).first, image.Power_Up_image(0).second);
	set_x(x);
	set_y(y);

	seed = std::chrono::system_clock::now().time_since_epoch().count();
	power_up.seed(seed);
}


Copy_Chip::~Copy_Chip()
{
}

void Copy_Chip::power_up_abilities(Player *& player, std::vector<Enemy*>& enemy)
{
	std::uniform_int_distribution <int> kind_of_powerup(0, 4);

	switch (kind_of_powerup(power_up))
	{

	case GLIDING_CHIP:
		player->set_vel(10);
		player->set_glide(true);
		player->set_delay_movemement(200);
		break;

	case HEALTH_CHIP:
		player->set_health(player->get_health() + 25);
		break;

	case NEEDLE_WIND_BLAST_CHIP:
		for (int i = 0; i < enemy.size(); i++)
		{
			if (enemy[i]->get_x() < player->get_x())
			{
				enemy.erase(enemy.begin() + i);
			}
		}
		break;

	case STOP_CHIP:
		for (int i = 0; i < enemy.size(); i++)
		{
			enemy[i]->set_vel(0);
		}
		break;

	case B_2_BOMBER_STRIKE_CHIP:
		enemy.clear();
		break;
	
	}
}
