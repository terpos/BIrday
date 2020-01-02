#include "Power_Up.h"

#pragma once
class Needle_Blast_Wind_Chip: public Power_Up
{
public:
	Needle_Blast_Wind_Chip(Image image, int x, int y);
	~Needle_Blast_Wind_Chip();


	void power_up_abilities(Sound sound, Player* &player, std::vector <Enemy*> &enemy, Options option);
private:
	int x, y;

	std::pair <ALLEGRO_BITMAP *, int> image;
};

