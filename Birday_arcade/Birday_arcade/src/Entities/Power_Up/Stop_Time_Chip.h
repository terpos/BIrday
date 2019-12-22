#include "Power_Up.h"

#pragma once
class Stop_Time_Chip: public Power_Up
{
public:
	Stop_Time_Chip(Image image, int x, int y);
	~Stop_Time_Chip();

	void power_up_abilities(Player* &player, std::vector <Enemy*> &enemy);

private:
	int x, y;

	std::pair <ALLEGRO_BITMAP *, int> image;
};

