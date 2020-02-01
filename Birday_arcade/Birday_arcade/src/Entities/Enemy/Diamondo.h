#include "Enemy.h"

#pragma once
class Diamondo: public Enemy
{
public:
	Diamondo(Image &sprite_sheet, int version, int x, int y, int vel, int direction);
	~Diamondo();

	int Damage();
	int get_score();

	void shoot(std::vector <E_Weapon*> &eweapon, Options option, Sound sound, Image spritesheet);


private:
	int x, y, vel, direction;
	unsigned int health;
	unsigned seed;

	int nochange;
	int reload_time;

	bool draw;
	std::pair <bool, int> hit;

	std::default_random_engine movement;
	std::default_random_engine shooting_probability;

};

