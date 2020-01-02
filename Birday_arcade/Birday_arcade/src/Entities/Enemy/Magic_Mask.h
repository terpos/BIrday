#include "Enemy.h"

#pragma once
class Magic_Mask: public Enemy
{
public:
	Magic_Mask(Image &sprite_sheet, int version, int x, int y, int vel, int direction);
	~Magic_Mask();

	int Damage();

	void shoot(std::vector <E_Weapon*> &eweapon, Options option, Sound sound, Image spritesheet);

private:
	int x, y, vel, direction;
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

