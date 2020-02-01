#include "Power_Up.h"

#pragma once
class B_2_Bomber_Strike_Chip: public Power_Up
{
public:
	B_2_Bomber_Strike_Chip(Image image, int x, int y);
	~B_2_Bomber_Strike_Chip();

	void power_up_abilities(Sound sound, Player* &player, std::vector <Enemy*> &enemy, Options option);

private:
	int x, y;

};

