#include "Enemy.h"

#pragma once
class Ball: public Enemy
{
public:
	Ball(Image &sprite_sheet, int version, int x, int y, int vel, int direction);
	~Ball();

	int Damage();
	int get_score();

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

