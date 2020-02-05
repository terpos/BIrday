#include "Power_Up.h"

#pragma once
class Copy_Chip:public Power_Up
{
public:
	Copy_Chip(Image image, int x, int y);
	~Copy_Chip();

	void power_up_abilities(Sound sound, Player* &player, std::vector <Enemy*> &enemy, std::vector <B_2_Bomber*> &b2, Options option);

	int get_random_powerup();

private:
	int x, y, seed, random;
	std::default_random_engine power_up;


};

