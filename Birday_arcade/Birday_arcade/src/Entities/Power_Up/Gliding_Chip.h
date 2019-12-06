#include "Power_Up.h"

#pragma once
class Gliding_Chip: public Power_Up
{
public:
	Gliding_Chip(Image image, int x, int y);
	~Gliding_Chip();

private:
	int x, y;

	std::pair <ALLEGRO_BITMAP *, int> image;
};

