#include "Collision.h"



Collision::Collision()
{
	seed = std::chrono::system_clock::now().time_since_epoch().count();
	change_direction.seed(seed);
}


Collision::~Collision()
{
}

void Collision::Window_Collision(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT & e, Player & player, Enemy* &enemy)
{
	std::uniform_int_distribution <int> d(0, 3);
	//std::cout << al_get_bitmap_width(player.get_bitmap().first) << ", " << al_get_bitmap_height(player.get_bitmap().first) << std::endl;

	if (player.get_x() < 0)
	{
		player.set_x(player.get_x() + player.get_vel());
	}

	else if (player.get_y() < 0)
	{
		player.set_y(player.get_y() + player.get_vel());
	}

	else if (player.get_x() + 80 > al_get_display_width(display))
	{
		player.set_x(player.get_x() - player.get_vel());
	}

	else if (player.get_y() + 80 > al_get_display_height(display))
	{
		player.set_y(player.get_y() - player.get_vel());
	}

	if (enemy->get_x() < 0 || enemy->get_y() < 0 || enemy->get_x() + 80 > al_get_display_width(display) || enemy->get_y() + 80 > al_get_display_height(display))
	{
		enemy->set_direction(d(change_direction));
	}	
}

bool Collision::collision_detect(int x, int y, int x2, int y2)
{
	if (x < x2 + 80 && x + 80 > x2 && y < y2 + 80 && y + 80 > y2)
	{
		return true;
	}



	return 0;
}
