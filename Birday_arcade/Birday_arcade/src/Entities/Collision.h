#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Enemy/Weapon/E_Weapon.h"
#include "Player/Weapon/P_Weapon.h"
#include "global.h"

#pragma once
class Collision
{
public:
	Collision();
	~Collision();

	void Window_Collision(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT &e, Player &player);
	void Window_Collision(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT & e, Enemy* & enemy);
	void Window_Collision(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT & e, std::vector <P_Weapon*> & pweapon, std::vector <E_Weapon *> &eweapon);

	bool collision_detect(int x, int y, int x2, int y2);

private:
	std::default_random_engine change_direction;

	unsigned seed;
};

