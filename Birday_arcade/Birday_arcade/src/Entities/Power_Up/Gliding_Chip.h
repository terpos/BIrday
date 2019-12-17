#include "Power_Up.h"

#pragma once
class Gliding_Chip: public Power_Up
{
public:
	Gliding_Chip(Image image, int x, int y);
	~Gliding_Chip();

	void power_up_abilities(Player &player, std::vector <Enemy*> &enemy);

private:
	int x, y;

	std::pair <ALLEGRO_BITMAP *, int> image;
};

