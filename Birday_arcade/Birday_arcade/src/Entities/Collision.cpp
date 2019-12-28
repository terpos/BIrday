#include "Collision.h"



Collision::Collision()
{
	seed = std::chrono::system_clock::now().time_since_epoch().count();
	change_direction.seed(seed);
}


Collision::~Collision()
{
}

void Collision::Window_Collision(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT & e, Player* & player)
{
	if (player->get_x() < 0)
	{
		player->set_x(player->get_x() + player->get_vel());
	}

	else if (player->get_y() < 0)
	{
		player->set_y(player->get_y() + player->get_vel());
	}

	else if (player->get_x() + 80 > al_get_display_width(display))
	{
		player->set_x(player->get_x() - player->get_vel());
	}

	else if (player->get_y() + 80 > 720)
	{
		player->set_y(player->get_y() - player->get_vel());
	}

	
}

void Collision::Window_Collision(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT & e, Enemy * & enemy)
{
	
	if (enemy->get_x() < 0 || enemy->get_y() < 0 || enemy->get_x() + 80 > al_get_display_width(display) || enemy->get_y() + 80 > 720)
	{
		enemy->change_direction();
	}
}

void Collision::Window_Collision(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT & e, std::vector <P_Weapon*> & pweapon, std::vector <E_Weapon *> &eweapon)
{
	for (int i = 0; i < pweapon.size(); i++)
	{
		if (pweapon[i]->get_x() < 0 || pweapon[i]->get_y() < 0 || pweapon[i]->get_x() + 80 > al_get_display_width(display) || pweapon[i]->get_y() + 80 > 720)
		{
			pweapon[i]->set_hit(true, pweapon[i]->is_hit().second);
		}

	}

	for (int i = 0; i < eweapon.size(); i++)
	{
		if (eweapon[i]->get_x() + 80 < 0 || eweapon[i]->get_y() + 80 < 0 || eweapon[i]->get_x() > al_get_display_width(display) || eweapon[i]->get_y() > 720)
		{
			eweapon.erase(eweapon.begin() + i);
		}

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
