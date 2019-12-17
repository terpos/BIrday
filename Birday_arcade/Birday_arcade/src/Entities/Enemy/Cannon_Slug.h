#include "Enemy.h"

#pragma once
class Cannon_Slug:public Enemy
{
public:
	Cannon_Slug(Image &sprite_sheet, int version, int x, int y, int vel, int direction);
	~Cannon_Slug();

	int Damage();

	void react(Image &image, Player &player, std::vector <E_Weapon*> &eweapon);
	void shoot(std::vector <E_Weapon*> &eweapon, Image spritesheet);

private:
	int x, y, vel, direction, initial_vel;
	unsigned int health;
	unsigned seed;

	int nochange;
	int reload_time;

	bool draw;
	std::pair <bool, int> hit;
	std::pair <ALLEGRO_BITMAP*, int> image;

	std::default_random_engine movement;
	std::default_random_engine shooting_probability;

	ALLEGRO_BITMAP* cropping;
};

