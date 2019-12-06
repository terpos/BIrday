#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "global.h"

#pragma once
class Collision
{
public:
	Collision();
	~Collision();

	void Window_Collision(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT &e, Player &player, Enemy* &enemy);
	bool collision_detect(int x, int y, int x2, int y2);

private:
	std::default_random_engine change_direction;

	unsigned seed;
};

