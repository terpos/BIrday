#include "Power_Up.h"

#pragma once
class B_2_Bomber_Strike_Chip: public Power_Up
{
public:
	B_2_Bomber_Strike_Chip(Image image, int x, int y);
	~B_2_Bomber_Strike_Chip();

	void power_up_abilities(Player &player, std::vector <Enemy*> &enemy);

private:
	int x, y;

	std::pair <ALLEGRO_BITMAP *, int> image;
};

