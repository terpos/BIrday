#include "Power_Up.h"

#pragma once
class Stop_Time_Chip: public Power_Up
{
public:
	Stop_Time_Chip(Image image, int x, int y);
	~Stop_Time_Chip();

private:
	int x, y;

	std::pair <ALLEGRO_BITMAP *, int> image;
};

