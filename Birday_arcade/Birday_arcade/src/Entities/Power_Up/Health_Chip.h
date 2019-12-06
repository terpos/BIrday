#include "Power_Up.h"

#pragma once
class Health_Chip: public Power_Up
{
public:
	Health_Chip(Image image, int x, int y);
	~Health_Chip();

private:
	int x, y;

	std::pair <ALLEGRO_BITMAP *, int> image;
};

